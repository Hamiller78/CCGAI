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

#include "MockGamepiece.h"
#include "MockPileFactory.h"
#include "MockPile.h"
#include "../Prototype/board.h"

TEST(Board, AddAndRemovePile)
{
    const mocks::MockPileFactory mockPileFactory;
    mocks::MockPile *mockPilePtr = new mocks::MockPile;
    game::Board testBoard(mockPileFactory);
    std::shared_ptr<game::IGamepiece> mockPiecePtr(new mocks::MockGamepiece);

    EXPECT_CALL(mockPileFactory, Create()).Times(1).WillOnce(Return(mockPilePtr));
    EXPECT_CALL(*mockPilePtr, AddOnTop(mockPiecePtr)).Times(1);
    testBoard.AddGamepiece(mockPiecePtr, game::Position (0, 0));

    testBoard.MovePile(game::Position (0, 0), game::Position(1, 1));

    EXPECT_CALL(*mockPilePtr, Die()).Times(1);
    testBoard.RemovePile(game::Position(1, 1));
}

TEST(Board, ExceptionThrownWhenMovingEmptyPosition)
{
    const mocks::MockPileFactory mockPileFactory;
    game::Board testBoard(mockPileFactory);

    EXPECT_THROW(testBoard.MovePile(game::Position(0, 0), game::Position(1, 1)), std::logic_error);
}

TEST(Board, ExceptionThrownWhenRemovingEmptyPosition)
{
    const mocks::MockPileFactory mockPileFactory;
    game::Board testBoard(mockPileFactory);

    EXPECT_THROW(testBoard.RemovePile(game::Position(2, 2)), std::logic_error);
}

TEST(Board, CombiningPilesWhenStackingGamepieces)
{
    const mocks::MockPileFactory mockPileFactory;
    mocks::MockPile *mockPilePtr1 = new mocks::MockPile;
    mocks::MockPile *mockPilePtr2 = new mocks::MockPile;
    game::Board testBoard(mockPileFactory);
    std::shared_ptr<game::IGamepiece> mockPiecePtr1(new mocks::MockGamepiece);
    std::shared_ptr<game::IGamepiece> mockPiecePtr2(new mocks::MockGamepiece);

    EXPECT_CALL(mockPileFactory, Create())
            .Times(2)
            .WillOnce(Return(mockPilePtr1))
            .WillOnce(Return(mockPilePtr2));
    testBoard.AddGamepiece(mockPiecePtr1, game::Position(0, 0));
    testBoard.AddGamepiece(mockPiecePtr2, game::Position(1, 0));

    EXPECT_CALL(*mockPilePtr2, AddPile(mockPilePtr1));
    EXPECT_CALL(*mockPilePtr1, Die()).Times(1);
    testBoard.MovePile(game::Position(0, 0), game::Position(1, 0));

    EXPECT_CALL(*mockPilePtr2, Die()).Times(1);
    testBoard.RemovePile(game::Position(1, 0));
}

TEST(Board, AddNewPieceDirectlyOnPile)
{
    const mocks::MockPileFactory mockPileFactory;
    mocks::MockPile *mockPilePtr = new mocks::MockPile;
    game::Board testBoard(mockPileFactory);
    std::shared_ptr<game::IGamepiece> mockPiecePtr1(new mocks::MockGamepiece);
    std::shared_ptr<game::IGamepiece> mockPiecePtr2(new mocks::MockGamepiece);

    EXPECT_CALL(mockPileFactory, Create())
            .Times(1)
            .WillOnce(Return(mockPilePtr));
    testBoard.AddGamepiece(mockPiecePtr1, game::Position(0, -1));

    EXPECT_CALL(*mockPilePtr, AddOnTop(mockPiecePtr2));
    testBoard.AddGamepiece(mockPiecePtr2, game::Position(0, -1));

    EXPECT_CALL(*mockPilePtr, Die()).Times(1);
    testBoard.RemovePile(game::Position(0, -1));
}

TEST(Board, TestAssignmentOperator)
{
    const mocks::MockPileFactory mockPileFactory;
    game::Board *sourceBoard = new game::Board(mockPileFactory);
    std::shared_ptr<game::IGamepiece> mockPiecePtr(new mocks::MockGamepiece);
    mocks::MockPile *mockPilePtr1 = new mocks::MockPile;
    mocks::MockPile *mockPilePtr2 = new mocks::MockPile;

    EXPECT_CALL(mockPileFactory, Create()).Times(1).WillOnce(Return(mockPilePtr1));
    sourceBoard->AddGamepiece(mockPiecePtr, game::Position(3, 2));

    EXPECT_CALL(*mockPilePtr1, CreateCopy()).Times(1).WillOnce(Return(mockPilePtr2));
    game::Board copyBoard = *sourceBoard;

    EXPECT_CALL(*mockPilePtr2, GetTopPiece()).Times(1).WillOnce(Return(mockPiecePtr));
    ASSERT_EQ(mockPiecePtr, copyBoard.GetTopPiece(game::Position(3, 2)));

    EXPECT_CALL(*mockPilePtr1, Die()).Times(1);
    delete sourceBoard;

    EXPECT_CALL(*mockPilePtr2, GetTopPiece()).Times(1).WillOnce(Return(mockPiecePtr));
    ASSERT_EQ(mockPiecePtr, copyBoard.GetTopPiece(game::Position(3, 2)));
}

TEST(Board, TestCopyConstructor)
{
    const mocks::MockPileFactory mockPileFactory;
    game::Board *sourceBoard = new game::Board(mockPileFactory);
    std::shared_ptr<game::IGamepiece> mockPiecePtr(new mocks::MockGamepiece);
    mocks::MockPile *mockPilePtr1 = new mocks::MockPile;
    mocks::MockPile *mockPilePtr2 = new mocks::MockPile;

    EXPECT_CALL(mockPileFactory, Create()).Times(1).WillOnce(Return(mockPilePtr1));
    sourceBoard->AddGamepiece(mockPiecePtr, game::Position(-7, 5));

    EXPECT_CALL(*mockPilePtr1, CreateCopy()).Times(1).WillOnce(Return(mockPilePtr2));
    game::Board copyBoard(*sourceBoard);

    EXPECT_CALL(*mockPilePtr2, GetTopPiece()).Times(1).WillOnce(Return(mockPiecePtr));
    ASSERT_EQ(mockPiecePtr, copyBoard.GetTopPiece(game::Position(-7, 5)));

    EXPECT_CALL(*mockPilePtr1, Die()).Times(1);
    delete sourceBoard;

    EXPECT_CALL(*mockPilePtr2, GetTopPiece()).Times(1).WillOnce(Return(mockPiecePtr));
    ASSERT_EQ(mockPiecePtr, copyBoard.GetTopPiece(game::Position(-7, 5)));
}

TEST(Board, CreateCopyAndCheckIndepence)
{
    const mocks::MockPileFactory mockPileFactory;
    game::Board *sourceBoard = new game::Board(mockPileFactory);
    std::shared_ptr<game::IGamepiece> mockPiecePtr(new mocks::MockGamepiece);
    mocks::MockPile *mockPilePtr1 = new mocks::MockPile;
    mocks::MockPile *mockPilePtr2 = new mocks::MockPile;

    EXPECT_CALL(mockPileFactory, Create()).Times(1).WillOnce(Return(mockPilePtr1));
    sourceBoard->AddGamepiece(mockPiecePtr, game::Position(-7, 5));

    EXPECT_CALL(*mockPilePtr1, CreateCopy()).Times(1).WillOnce(Return(mockPilePtr2));
    game::Board copyBoard = sourceBoard->CreateCopy();

    EXPECT_CALL(*mockPilePtr2, GetTopPiece()).Times(1).WillOnce(Return(mockPiecePtr));
    ASSERT_EQ(mockPiecePtr, copyBoard.GetTopPiece(game::Position(-7, 5)));

    EXPECT_CALL(*mockPilePtr1, Die()).Times(1);
    delete sourceBoard;

    EXPECT_CALL(*mockPilePtr2, GetTopPiece()).Times(1).WillOnce(Return(mockPiecePtr));
    ASSERT_EQ(mockPiecePtr, copyBoard.GetTopPiece(game::Position(-7, 5)));

}
