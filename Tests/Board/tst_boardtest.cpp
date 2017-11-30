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

public:
    BoardTest();

private Q_SLOTS:
    void initTestCase();
    void cleanupTestCase();
    void testCase1();
};

BoardTest::BoardTest()
{
}

void BoardTest::initTestCase()
{
    testBoard = new Board;
    testPiece1 = std::shared_ptr<Gamepiece>(new Gamepiece);
}

void BoardTest::cleanupTestCase()
{
    testPiece1.reset();
    delete testBoard;
}

void BoardTest::testCase1()
{
    testBoard->addGamepiece(testPiece1, Position (0, 0));
    testBoard->movePile(Position (0, 0), Position(1, 1));
    testBoard->removePile(Position(1, 1));
}

QTEST_APPLESS_MAIN(BoardTest)

#include "tst_boardtest.moc"
