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

#include "service.h"
#include "log.h"

Service::Service(std::shared_ptr<MainConfig> config)
        : config_(config) {
    server_manager_ = std::make_shared<ServerManager>(config_, io_service_);
}

void Service::run() {
    Log::log_with_date_time("shadowsocksrr-asio service started.", Log::Level::FATAL);
    // registe all async listen and async task
    server_manager_->run();
    // to run
    io_service_.run();
    Log::log_with_date_time("shadowsocksrr-asio service stopped", Log::Level::FATAL);
}

void Service::stop() {
    io_service_.stop();
}


