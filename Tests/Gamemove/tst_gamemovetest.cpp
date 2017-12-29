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
#include "../../Prototype/gamemovemovetop.h"
#include "../../Prototype/gamemovespawnpiece.h"

using namespace game;

class GamemoveTest : public QObject
{
    Q_OBJECT

private:
    GamemoveMovePile *moveMove;
    GamemoveMoveTop *moveTopMove;
    GamemoveSpawnPiece *moveSpawnMove;
    Board *testBoard;
    std::shared_ptr<Gamepiece> testPiece1;
    std::shared_ptr<Gamepiece> testPiece2;

public:
    GamemoveTest();

private Q_SLOTS:
    void initTestCase();
    void cleanupTestCase();
    void testCase1();
    void testCase2();
    void testCase3();
};

GamemoveTest::GamemoveTest()
{
}

void GamemoveTest::initTestCase()
{
    moveMove = new GamemoveMovePile(Position (0, 0), Position(1, 1));
    moveTopMove = new GamemoveMoveTop(Position (1, 1), Position(-1, -1));
    moveSpawnMove = new GamemoveSpawnPiece(1, Position(2,-1));
    testBoard = new Board;
    testPiece1 = std::shared_ptr<Gamepiece>(new Gamepiece);
    testPiece2 = std::shared_ptr<Gamepiece>(new Gamepiece);
}

void GamemoveTest::cleanupTestCase()
{
    testPiece1.reset();
    testPiece2.reset();
    delete testBoard;
    delete moveSpawnMove;
    delete moveMove;
}

void GamemoveTest::testCase1()
{
    Board resultBoard = moveSpawnMove->ApplyOnBoard(*testBoard);
    resultBoard.RemovePile(Position(2, -1));
}

void GamemoveTest::testCase2()
{
    testBoard->AddGamepiece(testPiece1, Position (0, 0));
    testBoard->AddGamepiece(testPiece2, Position (1, 1));
    Board resultBoard = moveMove->ApplyOnBoard(*testBoard);
    resultBoard.RemovePile(Position(1, 1));
}

void GamemoveTest::testCase3()
{
    testBoard->AddGamepiece(testPiece1, Position (0, 0));
    testBoard->AddGamepiece(testPiece2, Position (1, 1));
    Board resultBoard1 = moveMove->ApplyOnBoard(*testBoard);
    Board resultBoard2 = moveTopMove->ApplyOnBoard(resultBoard1);
    resultBoard2.RemovePile(Position(1, 1));
    resultBoard2.RemovePile(Position(-1, -1));
}

QTEST_APPLESS_MAIN(GamemoveTest)

#include "tst_gamemovetest.moc"
