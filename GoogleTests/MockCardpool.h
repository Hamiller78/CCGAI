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

#ifndef MOCKCARDPOOL_H
#define MOCKCARDPOOL_H

#include "gmock/gmock.h"
#include "../Prototype/cardpool.h"

namespace mocks {

class MockCardpool: public plugin::Cardpool
{
public:
    MockCardpool() {}
    ~MockCardpool() override {}

    MOCK_METHOD(std::shared_ptr<game::IGamepiece>, MakeCard, (int), (override, const));
    MOCK_METHOD(std::shared_ptr<game::IGamepiece>, MakeCard, (const QString&), (override, const));
    MOCK_METHOD(void, SetPool, (const QStringList&), (override));
};

} // namespace mocks

#endif // MOCKCARDPOOL_H
