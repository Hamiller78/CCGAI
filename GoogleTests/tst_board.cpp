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
    testBoard.RemovePile(game::Position(1, 1));

    // TODO: check that mock pile was deleted
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
    testBoard.MovePile(game::Position(0, 0), game::Position(1, 0));

    testBoard.RemovePile(game::Position(1, 0));
    // TODO: check that mock piles were deleted
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

    testBoard.RemovePile(game::Position(0, -1));
    // TODO: check that mock pile was deleted
}

TEST(Board, CopyByAssignmentOperator)
{
    const mocks::MockPileFactory mockPileFactory;
    game::Board *sourceBoard = new game::Board(mockPileFactory);
    std::shared_ptr<game::IGamepiece> mockPiecePtr(new mocks::MockGamepiece);
    mocks::MockPile *mockPilePtr1 = new mocks::MockPile;
    mocks::MockPile *mockPilePtr2 = new mocks::MockPile;

    EXPECT_CALL(mockPileFactory, Create()).Times(2).WillOnce(Return(mockPilePtr1))
                                                   .WillOnce(Return(mockPilePtr2));
    EXPECT_CALL(*mockPilePtr1, GetTopPiece()).Times(1).WillOnce(Return(mockPiecePtr));
    EXPECT_CALL(*mockPilePtr2, GetTopPiece()).Times(1).WillOnce(Return(mockPiecePtr));

    sourceBoard->AddGamepiece(mockPiecePtr, game::Position(3, 2));

    game::Board copyBoard = *sourceBoard;
    ASSERT_EQ(mockPiecePtr, copyBoard.GetTopPiece(game::Position(3, 2)));

    delete sourceBoard;
    ASSERT_EQ(mockPiecePtr, copyBoard.GetTopPiece(game::Position(3, 2)));


}

/*
void BoardTest::test_AssignmentOperator()
{
    Board *sourceBoard = new Board;
    sourceBoard->AddGamepiece(testPiece1_, Position(3, 2));
    Board copyBoard = *sourceBoard;
    QVERIFY2(testPiece1_ == copyBoard.GetTopPiece(Position(3, 2)),
      "Testpiece 1 not copied properly to new board.");
    delete sourceBoard;
    QVERIFY2(testPiece1_ == copyBoard.GetTopPiece(Position(3, 2)),
      "Testpiece 1 not found after deleting sourceBoard.");
}

void BoardTest::test_CopyConstructor()
{
    Board *sourceBoard = new Board;
    sourceBoard->AddGamepiece(testPiece1_, Position(3, 2));
    Board copyBoard(*sourceBoard);
    QVERIFY2(testPiece1_ == copyBoard.GetTopPiece(Position(3, 2)),
      "Testpiece 1 not copied properly to new board.");
    delete sourceBoard;
    QVERIFY2(testPiece1_ == copyBoard.GetTopPiece(Position(3, 2)),
      "Testpiece 1 not found after deleting sourceBoard.");
}

*/
