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
#include "../../Prototype/gamemove.h"
#include "../../Prototype/gamemovemovepile.h"
#include "../../Prototype/gamemovespawnpiece.h"

using namespace game;

class GamemoveTest : public QObject
{
    Q_OBJECT

private:
    GamemoveMovePile *moveMove;
    GamemoveSpawnPiece *spawnMove;
    Board *testBoard;
    std::shared_ptr<Gamepiece> testPiece1;

public:
    GamemoveTest();

private Q_SLOTS:
    void initTestCase();
    void cleanupTestCase();
    void testCase1();
    void testCase2();
};

GamemoveTest::GamemoveTest()
{
}

void GamemoveTest::initTestCase()
{
    moveMove = new GamemoveMovePile(Position (0, 0), Position(1, 1));
    spawnMove = new GamemoveSpawnPiece(1, Position(2,-1));
    testBoard = new Board;
    testPiece1 = std::shared_ptr<Gamepiece>(new Gamepiece);
}

void GamemoveTest::cleanupTestCase()
{
    testPiece1.reset();
    delete testBoard;
    delete spawnMove;
    delete moveMove;
}

void GamemoveTest::testCase1()
{
    Board resultBoard = spawnMove->applyOnBoard(*testBoard);
    resultBoard.removePile(Position(2, -1));
}

void GamemoveTest::testCase2()
{
    testBoard->addGamepiece(testPiece1, Position (0, 0));
    Board resultBoard = moveMove->applyOnBoard(*testBoard);
    resultBoard.removePile(Position(1, 1));
}

QTEST_APPLESS_MAIN(GamemoveTest)

#include "tst_gamemovetest.moc"
