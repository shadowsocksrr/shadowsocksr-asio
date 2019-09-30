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

#ifndef _LOG_H_
#define _LOG_H_

#include <string>
#include <boost/asio.hpp>
#include <stdexcept>
#include <utility>
#include <boost/lexical_cast.hpp>

#ifdef ERROR // windows.h
#undef ERROR
#endif // ERROR

class Log {
public:
    enum class Level {
        ALL = 0,
        INFO = 1,
        WARN = 2,
        ERROR = 3,
        FATAL = 4,
        OFF = 5
    };
    static Level level;

    static void log(const std::string &message, Level level = Level::ALL);

    static void log_with_date_time(const std::string &message, Level level = Level::ALL);

    static void log_with_endpoint(const boost::asio::ip::tcp::endpoint &endpoint,
                                  const std::string &message,
                                  Level level = Level::ALL);
};


class AssertError : public std::exception {
    std::string _reason;
//    std::string reason;
//    std::string files;
//    std::string lines;

public:
    explicit
    AssertError(const std::string &reason, const std::string &files, int lines)
            : _reason(std::string("AssertError : \"") + reason +
                      std::string("\" in file : \"") + files +
                      std::string("\" at line : ") + boost::lexical_cast<std::string>(lines)) {
        Log::log_with_date_time(_reason, Log::Level::FATAL);
    }

    explicit
    AssertError(const char *const reason, const char *const files, int lines)
            : _reason(std::string("AssertError : \"") + reason +
                      std::string("\" in file : \"") + files +
                      std::string("\" at line : ") + boost::lexical_cast<std::string>(lines)) {
        Log::log_with_date_time(_reason, Log::Level::FATAL);
    }

    AssertError(AssertError &&) = default;

    AssertError &operator=(AssertError &&) = default;

    AssertError(const AssertError &) = default;

    AssertError &operator=(const AssertError &) = default;

    virtual ~AssertError() = default;

    /** Returns a C-style character string describing the general cause of
     *  the current error (the same string passed to the ctor).  */
    virtual const char *what() const noexcept {
        return _reason.c_str();
    }

};

#define SSRR_Assert(expr) do { if(!!(expr)) ; else throw AssertError( #expr, __FILE__, __LINE__ ); } while(0)

#define SSRR_Throw(expr) do { throw AssertError( #expr, __FILE__, __LINE__ ); } while(0)

#endif // _LOG_H_
