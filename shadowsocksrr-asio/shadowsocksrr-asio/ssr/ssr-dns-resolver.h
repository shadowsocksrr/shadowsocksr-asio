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

#ifndef SSR_DNS_RESOLVER_H
#define SSR_DNS_RESOLVER_H

#include <memory>
#include <boost/asio.hpp>

class SsrDnsResolver : public std::enable_shared_from_this<SsrDnsResolver>
{
	boost::asio::io_service& io_service_;
	boost::asio::ip::tcp::resolver tcp_resolver;
	boost::asio::ip::udp::resolver udp_resolver;
public:
	SsrDnsResolver(boost::asio::io_service& io_service);
};

#endif	// SSR_DNS_RESOLVER_H
