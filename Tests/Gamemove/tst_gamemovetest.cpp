/* Copyright (c) 2017,2018 Torben Kneesch

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
#include "../../Prototype/cardpool.h"
#include "../../Prototype/gamemove.h"
#include "../../Prototype/gamemovemovepile.h"
#include "../../Prototype/gamemovemovetop.h"
#include "../../Prototype/gamemovespawnpiece.h"

using namespace game;

class GamemoveTest : public QObject
{
    Q_OBJECT

private:
    GamemoveMovePile *moveMove_;
    GamemoveMoveTop *moveTopMove_;
    GamemoveSpawnPiece *moveSpawnMove_;
    Board *testBoard_;
    std::shared_ptr<Gamepiece> testPiece1_;
    std::shared_ptr<Gamepiece> testPiece2_;

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
    moveMove_ = new GamemoveMovePile(Position (0, 0), Position(1, 1));
    moveTopMove_ = new GamemoveMoveTop(Position (1, 1), Position(-1, -1));
    moveSpawnMove_ = new GamemoveSpawnPiece(0, Position(2,-1));

    testBoard_ = new Board;
    testPiece1_ = std::shared_ptr<Gamepiece>(new Gamepiece);
    testPiece2_ = std::shared_ptr<Gamepiece>(new Gamepiece);

    plugin::Cardpool& testPool = plugin::Cardpool::GetInstance();
    QStringList testPoolData;
    testPoolData << "Name\tImageFile" << "Rookie\tRookie.jpeg";
    testPool.SetPool(testPoolData);
}

void GamemoveTest::cleanupTestCase()
{
    testPiece1_.reset();
    testPiece2_.reset();
    delete testBoard_;
    delete moveSpawnMove_;
    delete moveMove_;
}

void GamemoveTest::testCase1()
{
    Board resultBoard = moveSpawnMove_->ApplyOnBoard(*testBoard_);
    resultBoard.RemovePile(Position(2, -1));
}

void GamemoveTest::testCase2()
{
    testBoard_->AddGamepiece(testPiece1_, Position (0, 0));
    testBoard_->AddGamepiece(testPiece2_, Position (1, 1));
    Board resultBoard = moveMove_->ApplyOnBoard(*testBoard_);
    resultBoard.RemovePile(Position(1, 1));
}

void GamemoveTest::testCase3()
{
    testBoard_->AddGamepiece(testPiece1_, Position (0, 0));
    testBoard_->AddGamepiece(testPiece2_, Position (1, 1));
    Board resultBoard1 = moveMove_->ApplyOnBoard(*testBoard_);
    Board resultBoard2 = moveTopMove_->ApplyOnBoard(resultBoard1);
    resultBoard2.RemovePile(Position(1, 1));
    resultBoard2.RemovePile(Position(-1, -1));
}

QTEST_APPLESS_MAIN(GamemoveTest)

#include "tst_gamemovetest.moc"
