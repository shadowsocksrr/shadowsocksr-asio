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

#include "server-manager.h"

#include "ssr/ssr-server.h"

ServerManager::ServerManager(std::shared_ptr<MainConfig> config, boost::asio::io_service& io_service)
	:io_service_(io_service), config_(config)
{}


void ServerManager::run()
{
	// TODO this is DEBUG mock init, remove this when config analysis can use
	server_pool_.push_back(std::make_shared<SsrServer>(config_, std::make_shared<SsrConfig>(), io_service_));

	// TODO loop on a config tree to create all server
	// create and add server to server_pool_ 
	// TODO like above (like the up mock)
	;

	// start all server
	for (auto& a : server_pool_)
	{
		a->run();
	}
	// and all server will auto release on dtor or it end
}
