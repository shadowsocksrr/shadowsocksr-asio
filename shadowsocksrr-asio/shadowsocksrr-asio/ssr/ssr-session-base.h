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

#ifndef SSR_SESSION_BASE_H
#define SSR_SESSION_BASE_H

#include <memory>
#include <boost/asio.hpp>
#include "ssr-server.h"

 // tcp session server/client base interface
class SsrSessionBase : public std::enable_shared_from_this<SsrSessionBase>
{
protected:
	// handle weak a ref to parents server to take access for output debug info
	std::weak_ptr<BaseServer> parents_server_ref_;

	template<typename T = SsrServer>
	std::shared_ptr<T> get_parents_server_ref_() const;

public:
	virtual ~SsrSessionBase() = default;
	virtual boost::asio::ip::tcp::socket& accept_socket() = 0;
	virtual void start() = 0;
};

// get a derived type of BaseServer shared_ptr
// maybe null if weak_ptr are deleted
template <typename T>
std::shared_ptr<T> SsrSessionBase::get_parents_server_ref_() const
{
	return std::dynamic_pointer_cast<T>(parents_server_ref_.lock());
}

#endif	// SSR_SESSION_BASE_H
