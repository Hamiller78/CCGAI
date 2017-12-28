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
    Board *testBoard;
    std::shared_ptr<Gamepiece> testPiece1;
    std::shared_ptr<Gamepiece> testPiece2;

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
    testBoard = new Board;
    testPiece1 = std::shared_ptr<Gamepiece>(new Gamepiece);
    testPiece2 = std::shared_ptr<Gamepiece>(new Gamepiece);
}

void BoardTest::cleanupTestCase()
{
    testPiece1.reset();
    testPiece2.reset();
    delete testBoard;
}

void BoardTest::testCase1()
{
    // add a gamepiece, move it and remove it
    testBoard->addGamepiece(testPiece1, Position (0, 0));
    testBoard->movePile(Position (0, 0), Position(1, 1));
    testBoard->removePile(Position(1, 1));
}

void BoardTest::testCase2()
{
    // move non-existing pile to test exceptions
    QVERIFY_EXCEPTION_THROWN(testBoard->movePile(Position (0, 0),
                                                 Position(1, 1)), std::logic_error);
    QVERIFY_EXCEPTION_THROWN(testBoard->removePile(Position(2, 2)), std::logic_error);
}

void BoardTest::testCase3()
{
    // test pile handling
    testBoard->addGamepiece(testPiece1, Position (0, 0));
    testBoard->addGamepiece(testPiece2, Position (1, 0));
    testBoard->movePile(Position (0, 0), Position(1, 0));
    testBoard->movePile(Position (1, 0), Position(0, 0));
    QVERIFY2(testPiece1 == testBoard->getTopPiece(Position(0, 0)),
      "Testpiece 1 not found on top at (0,0).");
    testBoard->moveTopPiece(Position (0, 0), Position(2, 0));
    QVERIFY2(testPiece2 == testBoard->getTopPiece(Position(0, 0)),
      "Testpiece 2 not found on top at (0,0).");
    testBoard->removePile(Position(0, 0));
    QVERIFY_EXCEPTION_THROWN(testBoard->removePile(Position(1, 0));, std::logic_error);
}

QTEST_APPLESS_MAIN(BoardTest)

#include "tst_boardtest.moc"
