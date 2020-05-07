/*
 * Copyright (C) 2019 Medusalix
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#pragma once

#include <string>

class Bytes;

/*
 * Provides logging functions for different log levels
 * Debug logging can be enabled by defining DEBUG
 */
namespace Log
{
    std::string formatBytes(const Bytes &bytes);
    std::string formatLog(std::string level, std::string message);

    inline void init()
    {
        // Disable buffering
        setbuf(stdout, nullptr);
    }

    template<typename... Args>
    inline void debug(std::string message, Args... args)
    {
        #ifdef DEBUG
        std::string output = formatLog("DEBUG", message);
        std::fprintf(stdout, output.c_str(), args...);
        #endif
    }

    template<typename... Args>
    inline void info(std::string message, Args... args)
    {
        std::string output = formatLog("INFO", message);
        std::fprintf(stdout, output.c_str(), args...);
    }

    template<typename... Args>
    inline void error(std::string message, Args... args)
    {
        std::string output = formatLog("ERROR", message);
        std::fprintf(stdout, output.c_str(), args...);
    }
}
