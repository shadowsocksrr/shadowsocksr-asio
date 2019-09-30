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

#include "main-config.h"

#include "log.h"

#include <fstream>
#include <boost/filesystem.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

namespace pt = boost::property_tree;
namespace fs = boost::filesystem;

MainConfig::MainConfig() {
}

// load from file
void MainConfig::loadFile(std::string path) {
    fs::path p{path};
    if (!fs::is_regular_file(p)) {
//        Log::log_with_date_time("config file path not a regular_file.", Log::Level::FATAL);
        SSRR_Throw("config file path not a regular_file. path:" + path);
    }
    std::ifstream ifs{path};

    pt::ptree ptree;
    try {
        pt::read_json(ifs, ptree);
    } catch (const pt::json_parser_error &e) {
        SSRR_Throw("config file read_json error. what: \"" + e.what() + "\"");
    }

    // TODO read json ptree
    ;

}

void MainConfig::loadJsonString(std::string jsonString) {

    pt::ptree ptree;
    try {
        pt::read_json(jsonString, ptree);
    } catch (const pt::json_parser_error &e) {
        SSRR_Throw("config json string read_json error. what: \"" + e.what() + "\"");
    }

    // TODO read json ptree
    ;

}

// analysis a config string which come from file or command
bool MainConfig::analysis() {
    this->inited = true;
    return this->inited;
}

bool MainConfig::isInitOk() const {
    return this->inited;
}

