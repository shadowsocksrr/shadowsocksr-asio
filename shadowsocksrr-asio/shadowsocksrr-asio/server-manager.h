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

#ifndef ARCHITECT_SERVER_MANAGER_H
#define ARCHITECT_SERVER_MANAGER_H
#include <memory>
#include <list>
#include <boost/asio.hpp>
#include "base-server.h"

class ServerManager : public std::enable_shared_from_this<ServerManager>
{
private:
	boost::asio::io_service& io_service_;
	std::shared_ptr<MainConfig> config_;
	std::list<std::shared_ptr<BaseServer>> server_pool_;
public:
	ServerManager(std::shared_ptr<MainConfig> config, boost::asio::io_service& io_service);
	void run();
};


#endif	// ARCHITECT_SERVER_MANAGER_H
