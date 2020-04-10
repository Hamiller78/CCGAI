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

<<<<<<< HEAD:Prototype/IoHelper/ioexception.cpp
#include "ioexception.h"

namespace iohelper {

const char *IoException::what() const noexcept
{
    return this->errortext_.c_str();
}

} // namespace iohelper
=======
#include "tst_googletest.h"

#include <gtest/gtest.h>

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
>>>>>>> f86e82a8dd36904683b5f886e16217e5f5fd74b6:GoogleTests/main.cpp
