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

    std::unique_ptr<game::IBoard> mockBoardPtr(new mocks::MockBoard);
    game::GameState testState(std::move(mockBoardPtr));

    testState.SetPoints(3, 42);
    ASSERT_EQ(42, testState.GetPoints(3));

    testState.AlterPoints(3, 10);
    ASSERT_EQ(52, testState.GetPoints(3));

    testState.AlterPoints(3, -18);
    ASSERT_EQ(34, testState.GetPoints(3));
}

TEST(GameState, ExceptionWhenChangingNumberOfPointCounters)
{
    std::unique_ptr<game::IBoard> mockBoardPtr = std::unique_ptr<game::IBoard>(new mocks::MockBoard);
    game::GameState testState(std::move(mockBoardPtr));

    EXPECT_THROW(game::GameState::SetNumberOfPointCounters(3), std::runtime_error);
}

TEST(GameState, CopyByAssignmentOperator)
{
    std::unique_ptr<mocks::MockBoard> boardMockPtr1(new mocks::MockBoard);
    std::unique_ptr<mocks::MockBoard> boardMockPtr2(new mocks::MockBoard);
    // we need to keep pointers to the mocks as raw pointers,
    // since we will pass the unique_ptr to the Gamestate objects under test
    mocks::MockBoard* boardMockRawPtr1 = boardMockPtr1.get();
    mocks::MockBoard* boardMockRawPtr2 = boardMockPtr2.get();

    game::GameState sourceState(std::move(boardMockPtr1));
    sourceState.SetPoints(0, 42);

    EXPECT_CALL(*boardMockRawPtr1, Clone())
            .Times(1)
            .WillOnce(Return(ByMove(std::move(boardMockPtr2))));
    game::GameState copiedState = sourceState;

    sourceState.SetPoints(0, 13);
    ASSERT_EQ(13, sourceState.GetPoints(0));
    ASSERT_EQ(42, copiedState.GetPoints(0));
    ASSERT_EQ(boardMockRawPtr2, copiedState.GetBoard().get());
}

TEST(GameState, CopyByCopyConstructor)
{
    std::unique_ptr<mocks::MockBoard> boardMockPtr1(new mocks::MockBoard);
    std::unique_ptr<mocks::MockBoard> boardMockPtr2(new mocks::MockBoard);
    // we need to keep pointers to the mocks as raw pointers,
    // since we will pass the unique_ptr to the Gamestate objects under test
    mocks::MockBoard* boardMockRawPtr1 = boardMockPtr1.get();
    mocks::MockBoard* boardMockRawPtr2 = boardMockPtr2.get();

    game::GameState sourceState(std::move(boardMockPtr1));
    sourceState.SetPoints(0, 42);

    EXPECT_CALL(*boardMockRawPtr1, Clone())
            .Times(1)
            .WillOnce(Return(ByMove(std::move(boardMockPtr2))));
    game::GameState copiedState(sourceState);

    sourceState.SetPoints(0, 13);
    ASSERT_EQ(13, sourceState.GetPoints(0));
    ASSERT_EQ(42, copiedState.GetPoints(0));
    ASSERT_EQ(boardMockRawPtr2, copiedState.GetBoard().get());
}
