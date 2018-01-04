/* Copyright (c) 2017 Torben Kneesch

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

#include <QString>
#include <QtTest>

#include "../../Prototype/board.h"

#include "memory"

using namespace game;

class BoardTest : public QObject
{
    Q_OBJECT

private:
    Board *testBoard_;
    std::shared_ptr<Gamepiece> testPiece1_;
    std::shared_ptr<Gamepiece> testPiece2_;

public:
    BoardTest();

private Q_SLOTS:
    void initTestCase();
    void cleanupTestCase();
    void testCase1();
    void testCase2();
    void testCase3();
};

BoardTest::BoardTest()
{
}

void BoardTest::initTestCase()
{
    testBoard_ = new Board;
    testPiece1_ = std::shared_ptr<Gamepiece>(new Gamepiece);
    testPiece2_ = std::shared_ptr<Gamepiece>(new Gamepiece);
}

void BoardTest::cleanupTestCase()
{
    testPiece1_.reset();
    testPiece2_.reset();
    delete testBoard_;
}

void BoardTest::testCase1()
{
    // add a gamepiece, move it and remove it
    testBoard_->AddGamepiece(testPiece1_, Position (0, 0));
    testBoard_->MovePile(Position (0, 0), Position(1, 1));
    testBoard_->RemovePile(Position(1, 1));
}

void BoardTest::testCase2()
{
    // move non-existing pile to test exceptions
    QVERIFY_EXCEPTION_THROWN(testBoard_->MovePile(Position (0, 0),
                                                 Position(1, 1)), std::logic_error);
    QVERIFY_EXCEPTION_THROWN(testBoard_->RemovePile(Position(2, 2)), std::logic_error);
}

void BoardTest::testCase3()
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
    QVERIFY_EXCEPTION_THROWN(testBoard_->RemovePile(Position(1, 0));, std::logic_error);
}

QTEST_APPLESS_MAIN(BoardTest)

#include "tst_boardtest.moc"
