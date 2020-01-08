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
#include "../Prototype/board.h"
#include "../Prototype/objfactory.h"
#include "../Prototype/pile.h"

TEST(Board, AddAndRemovePile)
{
    ObjFactory<game::Pile> pileFactory;
    game::Board testBoard(pileFactory);
    std::shared_ptr<game::IGamepiece> testPiecePtr(new mocks::MockGamepiece);

    testBoard.AddGamepiece(testPiecePtr, game::Position (0, 0));
    testBoard.MovePile(game::Position (0, 0), game::Position(1, 1));
    testBoard.RemovePile(game::Position(1, 1));
}

TEST(Board, ExceptionThrownWhenMovingEmptyPosition)
{
    ObjFactory<game::Pile> pileFactory;
    game::Board testBoard(pileFactory);

    EXPECT_THROW(testBoard.MovePile(game::Position(0, 0), game::Position(1, 1)), std::logic_error);
 }

TEST(Board, ExceptionThrownWhenRemovingEmptyPosition)
{
    ObjFactory<game::Pile> pileFactory;
    game::Board testBoard(pileFactory);

    EXPECT_THROW(testBoard.RemovePile(game::Position(2, 2)), std::logic_error);
}

/*
TEST(Pile, AddGamepieces)
{
    game::Pile testPile1;
    std::shared_ptr<game::IGamepiece> testPiecePtr1(new mocks::MockGamepiece);
    std::shared_ptr<game::IGamepiece> testPiecePtr2(new mocks::MockGamepiece);
    std::shared_ptr<game::IGamepiece> testPiecePtr3(new mocks::MockGamepiece);

    testPile1.AddOnTop(testPiecePtr1);
    ASSERT_EQ(testPiecePtr1, testPile1.GetTopPiece());
    testPile1.AddOnTop(testPiecePtr2);
    ASSERT_EQ(testPiecePtr2, testPile1.GetTopPiece());
    testPile1.AddOnTop(testPiecePtr3);
    ASSERT_EQ(testPiecePtr3, testPile1.GetTopPiece());
    ASSERT_EQ(3, testPile1.GetPilesize());
}

void BoardTest::test_PileHandling()
{
    // test pile handling
    testBoard_->AddGamepiece(testPiece1_, Position (0, 0));
    testBoard_->AddGamepiece(testPiece2_, Position (1, 0));
    testBoard_->MovePile(Position (0, 0), Position(1, 0));
    testBoard_->MovePile(Position (1, 0), Position(0, 0));
    QVERIFY2(testPiece1_ == testBoard_->GetTopPiece(Position(0, 0)),
      "Testpiece 1 not found on top at (0,0).");
    testBoard_->MoveTopPiece(Position (0, 0), Position(2, 0));
    QVERIFY2(testPiece2_ == testBoard_->GetTopPiece(Position(0, 0)),
      "Testpiece 2 not found on top at (0,0).");
    testBoard_->RemovePile(Position(0, 0));
    testBoard_->RemovePile(Position(2, 0));
    QVERIFY_EXCEPTION_THROWN(testBoard_->RemovePile(Position(1, 0));, std::logic_error);
}

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
