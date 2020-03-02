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

#include "tst_googletest.h"

#include "MockBoard.h"
#include "MockPileFactory.h"
#include "../Prototype/gamestate.h"


TEST(GameState, GetDefaultNumberOfPointCounters)
{
    ASSERT_EQ(2, game::GameState::GetNumberOfPointCounters());
}

TEST(GameState, SetNumberOfPointCounters)
{
    game::GameState::SetNumberOfPointCounters(7);
    ASSERT_EQ(7, game::GameState::GetNumberOfPointCounters());
}

TEST(GameState, SetAndAlterPoints)
{
    game::GameState::SetNumberOfPointCounters(4);

    const mocks::MockPileFactory mockPileFactory;
    mocks::MockBoard boardMock(mockPileFactory);
    game::GameState testState(boardMock);

    testState.SetPoints(3, 42);
    ASSERT_EQ(42, testState.GetPoints(3));

    testState.AlterPoints(3, 10);
    ASSERT_EQ(52, testState.GetPoints(3));

    testState.AlterPoints(3, -18);
    ASSERT_EQ(34, testState.GetPoints(3));
}

TEST(GameState, ExceptionWhenChangingNumberOfPointCounters)
{
    const mocks::MockPileFactory mockPileFactory;
    mocks::MockBoard boardMock(mockPileFactory);
    game::GameState testState(boardMock);

    EXPECT_THROW(game::GameState::SetNumberOfPointCounters(3), std::runtime_error);
}

TEST(GameState, CopyByAssignmentOperator)
{
    const mocks::MockPileFactory mockPileFactory;
    mocks::MockBoard boardMock(mockPileFactory);
    game::GameState sourceState(boardMock);

    sourceState.SetPoints(0, 42);

    game::GameState copiedState = sourceState;
    sourceState.SetPoints(0, 13);
    ASSERT_EQ(42, copiedState.GetPoints(0));
}

/*
void GameStateTest::test_AssignmentOperator()
{
    GameState *sourceState = new GameState(pileFactory_);
    sourceState->SetPoints(0, 42);
    GameState copyState = *sourceState;
    QVERIFY2(42 == copyState.GetPoints(0),
      "Value of point index 0 not copied properly to new GameState.");
    delete sourceState;
    QVERIFY2(42 == copyState.GetPoints(0),
      "Point value not found after deleting sourceState.");
}
*/
