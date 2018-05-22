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

#ifndef SSR_UDP_CLIENT_H
#define SSR_UDP_CLIENT_H

#include <memory>
#include <map>
#include <boost/asio.hpp>

#include <boost/multi_index_container.hpp>
#include <boost/multi_index/sequenced_index.hpp>
#include <boost/multi_index/ordered_index.hpp>
#include <boost/multi_index/member.hpp>
#include <boost/multi_index/tag.hpp>

#include "ssr-config.h"
#include "ssr-udp-base.h"

class SsrUdpClient;
class SsrUdpClientSession : public std::enable_shared_from_this<SsrUdpClientSession>
{
	std::weak_ptr<SsrUdpBase> parents_server_ref_;
public:
	// user client endpoint (port and ip)
	boost::asio::ip::udp::endpoint endpoint_in_;
	// ssr client to ssr server local endpoint (port)
	boost::asio::ip::udp::endpoint endpoint_out_;
	// ssr client to ssr server UDP socket
	// need listen to receive remote return package
	boost::asio::ip::udp::socket socket_out_;
	// deadline_timer timer
	// to count timeout since last transfor
	// when receive or send UDP package, reset timer to 0 to re-count
	boost::asio::deadline_timer timer_;

	SsrUdpClientSession(boost::asio::io_service& io_service, std::shared_ptr<SsrUdpClient> parents_server_ref);
	void start(boost::asio::ip::udp::endpoint endpoint_in);
	// a package recevie from user client and need send to sr server
	void next_package(/*TODO*/);

};

// struct for SsrUdpClientSessionContainer
struct SsrUdpClientSessionContainerStruct
{
public:
	boost::asio::ip::address address_in_$;
	boost::asio::ip::address address_out_$;
	int port_in_$;
	int port_out_$;
	std::shared_ptr<SsrUdpClientSession> ref;
};

// tags for SsrUdpClientSessionContainer
struct SUCSC_user_addr{};
struct SUCSC_user_port{};
struct SUCSC_listen_addr{};
struct SUCSC_listen_port{};

using SsrUdpClientSessionContainer = boost::multi_index_container<
	SsrUdpClientSessionContainerStruct,
	boost::multi_index::indexed_by<
	boost::multi_index::sequenced<>,
	boost::multi_index::ordered_non_unique<
	boost::multi_index::tag<SUCSC_user_addr>,
	boost::multi_index::member<SsrUdpClientSessionContainerStruct, boost::asio::ip::address, &SsrUdpClientSessionContainerStruct::address_in_$>
	>,
	boost::multi_index::ordered_non_unique<
	boost::multi_index::tag<SUCSC_user_port>,
	boost::multi_index::member<SsrUdpClientSessionContainerStruct, boost::asio::ip::address, &SsrUdpClientSessionContainerStruct::address_out_$>
	>,
	boost::multi_index::ordered_non_unique<
	boost::multi_index::tag<SUCSC_listen_addr>,
	boost::multi_index::member<SsrUdpClientSessionContainerStruct, int, &SsrUdpClientSessionContainerStruct::port_in_$>
	>,
	boost::multi_index::ordered_non_unique<
	boost::multi_index::tag<SUCSC_listen_port>,
	boost::multi_index::member<SsrUdpClientSessionContainerStruct, int, &SsrUdpClientSessionContainerStruct::port_out_$>
	>
	>
>;

class SsrUdpClient : public SsrUdpBase
{
	boost::asio::io_service& io_service_;
	std::shared_ptr<SsrConfig> ssr_config_;

	// local socks5 endpoint
	boost::asio::ip::udp::endpoint endpoint_in_;
	// remote ssr server endpoint
	boost::asio::ip::udp::endpoint endpoint_server_;
	// ssr client UDP listen socket, same port as TCP
	// use to receive all user client income AND send back UDP package
	boost::asio::ip::udp::socket socket_in_;
	// [(user client UDP endpoint)(output listen port)]   TO   (SsrUdpClientSession)  key-pair
	SsrUdpClientSessionContainer session_container_;
	// ssr stack ref
	// TODO
	// socks5 stack ref
	// TODO

public:
	SsrUdpClient(std::shared_ptr<SsrConfig> ssr_config, boost::asio::io_service& io_service, std::shared_ptr<SsrServer> parents_server_ref);

	void start() override;
};

#endif	// SSR_UDP_CLIENT_H
