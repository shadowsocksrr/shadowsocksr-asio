/*
 *  This file is part of the shadowsocksrr-asio project.
 *  shadowsocksrr-asio is a shadowsocksr implement which driven by boost.asio.
 *  Copyright (C) 2018  Akkariiin
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <memory>
#include <cassert>
#include <boost/asio.hpp>

#include "../log.h"

#include "ssr-server.h"
#include "ssr-config.h"
#include "ssr-session-base.h"
#include "ssr-session-client.h"
#include "ssr-session-server.h"
#include "ssr-udp-base.h"
#include "ssr-udp-server.h"
#include "ssr-udp-client.h"

SsrServer::SsrServer(std::shared_ptr<MainConfig> config, std::shared_ptr<SsrConfig> ssr_config, boost::asio::io_service& io_service)
	:BaseServer(config, io_service),
	ssr_config_(ssr_config)
{
	// TODO set mode by config
	mode = Mode::SERVER;

	// TODO load from ssr config and init endpoint
	listen_endpoint_ = boost::asio::ip::tcp::endpoint(
		boost::asio::ip::make_address("127.0.0.1"),
		21000
	);

	tcp_acceptor_ = std::make_unique<boost::asio::ip::tcp::acceptor>(io_service_, listen_endpoint_);

}

void SsrServer::run()
{
	// run tcp
	this->async_accept();
	// run udp
	auto self = std::dynamic_pointer_cast<SsrServer>(this->shared_from_this());
	// read config to create a client side or server side
	switch (mode)
	{
	case Mode::CLIENT:
		this->ssr_udp_relay_ = std::dynamic_pointer_cast<SsrUdpBase>(std::make_shared<SsrUdpClient>(ssr_config_, io_service_, self));
		break;
	case Mode::SERVER:
		this->ssr_udp_relay_ = std::dynamic_pointer_cast<SsrUdpBase>(std::make_shared<SsrUdpServer>(ssr_config_, io_service_, self));
		break;
	default:
		assert(false && "server mode wrong");
		break;
	}
	this->ssr_udp_relay_->start();
}

void SsrServer::async_accept()
{

	std::shared_ptr<SsrSessionBase> ssr_side_stack_;

	auto self = std::dynamic_pointer_cast<SsrServer>(this->shared_from_this());

	// read config to create a client side or server side
	switch (mode)
	{
	case Mode::CLIENT:
		ssr_side_stack_ = std::make_shared<SsrSessionClient>(ssr_config_, io_service_, self);
		break;
	case Mode::SERVER:
		ssr_side_stack_ = std::make_shared<SsrSessionServer>(ssr_config_, io_service_, self);
		break;
	default:
		assert(false && "server mode wrong");
		break;
	}

	// bind listen to io_service
	tcp_acceptor_->async_accept(
		ssr_side_stack_->accept_socket(),
		[this, self, ssr_side_stack_](const boost::system::error_code error)
	{
		if (!error)
		{
			// debug log
			boost::system::error_code ec;
			auto endpoint = ssr_side_stack_->accept_socket().remote_endpoint(ec);
			if (!ec) {
				Log::log_with_endpoint(endpoint, "incoming connection");
			}
			// run
			ssr_side_stack_->start();
		}
		// next
		async_accept();
	}
	);

}
