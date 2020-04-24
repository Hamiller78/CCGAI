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

#ifndef MOCKBOARD_H
#define MOCKBOARD_H

#include "gmock/gmock.h"
#include "MockPileFactory.h"
#include "../Prototype/iboard.h"

namespace mocks {

class MockBoard : public game::IBoard
{
public:
    const MockPileFactory mockFactory;

    MockBoard() {}
    virtual ~MockBoard() override {}

    MOCK_METHOD(std::unique_ptr<game::IBoard>, Clone, (), (override, const));

    MOCK_METHOD(void, AddGamepiece, (const std::shared_ptr<game::IGamepiece>, const game::Position&), (override));
    MOCK_METHOD(std::shared_ptr<game::IGamepiece>, GetTopPiece, (const game::Position&), (override, const));
    MOCK_METHOD(void, MovePile, (const game::Position&, const game::Position&),(override));
    MOCK_METHOD(void, MoveTopPiece, (const game::Position&, const game::Position&), (override));
    MOCK_METHOD(void, RemovePile, (const game::Position&), (override));
};

} // namespace mocks

#endif // MOCKBOARD_H
