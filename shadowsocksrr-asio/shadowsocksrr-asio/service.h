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

#ifndef SERVICE_H
#define SERVICE_H

#include <memory>
#include <boost/asio.hpp>
#include "server-manager.h"

class Service : public std::enable_shared_from_this<Service>
{
private:
	boost::asio::io_service io_service_;
	std::shared_ptr<MainConfig> config_;
	std::shared_ptr<ServerManager> server_manager_;
public:
	Service(std::shared_ptr<MainConfig> config);
	void run();
	void stop();
};


#endif // SERVICE_H
