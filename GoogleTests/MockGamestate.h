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

#ifndef MOCKGAMESTATE_H
#define MOCKGAMESTATE_H

#include "gmock/gmock.h"
#include "../Prototype/igamestate.h"

namespace mocks {

class MockGameState: public game::IGameState
{
public:
    MockGameState() {}
    virtual ~MockGameState() override {}

    MOCK_METHOD(std::unique_ptr<game::IGameState>, Clone, (), (override, const));
    MOCK_METHOD(game::IBoard&, GetBoard, (), (override));
};

} // namespace mocks

#endif // MOCKGAMESTATE_H
