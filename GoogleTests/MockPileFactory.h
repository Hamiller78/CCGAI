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

#ifndef MOCKOBJFACTORY_H
#define MOCKOBJFACTORY_H

#include "gmock/gmock.h"
#include "../Prototype/objfactory.h"
#include "../Prototype/pile.h"

namespace mocks {

class MockPileFactory: public ObjFactory<game::Pile>
{
public:
    MockPileFactory() {}
    ~MockPileFactory() override {}
    MOCK_METHOD(game::Pile*, Create, (), (const, override));
};

} // namespace mocks

#endif // MOCKOBJFACTORY_H
