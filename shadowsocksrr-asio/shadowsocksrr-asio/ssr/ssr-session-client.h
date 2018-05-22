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

#ifndef SSR_SIDE_CLIENT_H
#define SSR_SIDE_CLIENT_H

#include <memory>
#include <boost/asio.hpp>
#include "ssr-config.h"
#include "ssr-session-base.h"

class SsrSessionClient : public SsrSessionBase
{
	boost::asio::io_service& io_service_;
	std::shared_ptr<SsrConfig> ssr_config_;

	boost::asio::ip::tcp::socket socket_in_;
	boost::asio::ip::tcp::socket socket_out_;
public:
	SsrSessionClient(std::shared_ptr<SsrConfig> ssr_config, boost::asio::io_service& io_service, std::shared_ptr<SsrServer> parents_server_ref);

	boost::asio::ip::tcp::socket& accept_socket() override;
	void start() override;
};


#endif	// SSR_SIDE_CLIENT_H
