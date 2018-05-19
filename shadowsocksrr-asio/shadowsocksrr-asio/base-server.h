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

#ifndef BASE_SERVER_H
#define BASE_SERVER_H

#include <memory>
#include <boost/asio.hpp>
#include "main-config.h"

// BaseServer is a pure virtual class
// it's a base parents class that define all server interface, 
// which interface use by ServerManager
class BaseServer : public std::enable_shared_from_this<BaseServer>
{
protected:
	boost::asio::io_service& io_service_;
	std::shared_ptr<MainConfig> config_;

public:
	BaseServer(std::shared_ptr<MainConfig> config, boost::asio::io_service& io_service);
	virtual ~BaseServer() = default;
	virtual void run() = 0;
};


#endif	// BASE_SERVER_H
