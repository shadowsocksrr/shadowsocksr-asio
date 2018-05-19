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

#ifndef SSR_SERVER_H
#define SSR_SERVER_H
#include "../base-server.h"
#include "ssr-config.h"

class SsrServer : public BaseServer
{
protected:
	std::shared_ptr<SsrConfig> ssr_config_;


public:
	SsrServer(std::shared_ptr<MainConfig> config, boost::asio::io_service& io_service);
	void run() override;
};




#endif	// SSR_SERVER_H
