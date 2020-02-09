/* Copyright (c) 2020 Torben Kneesch

 This file is part of the CCGAI Framework

 The CCGAI Framework is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 The CCGAI Framework is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with CCGAI Framework.  If not, see <http://www.gnu.org/licenses/>. */

#ifndef IOEXCEPTION_H
#define IOEXCEPTION_H

#include <string>

namespace iowrapper {

class IoException : public std::exception
{
private:
    std::string errortext_;
public:
    IoException(std::string errortext){errortext_ = errortext;}
    const char* what() const noexcept override;
};

} // namespace iowrapper

#endif // IOEXCEPTION_H
