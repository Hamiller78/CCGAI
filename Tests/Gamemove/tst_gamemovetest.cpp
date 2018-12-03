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

#include "../../Prototype/cardpool.h"
#include "../../Prototype/gamemove.h"
#include "../../Prototype/gamemovemovepile.h"
#include "../../Prototype/gamemovemovetop.h"
#include "../../Prototype/gamemovespawnpiece.h"
#include "../../Prototype/gamestate.h"


using namespace game;

class GamemoveTest : public QObject
{
    Q_OBJECT

private:
    std::shared_ptr<GameState> testState_;
    std::shared_ptr<Gamepiece> testPiece1_;
    std::shared_ptr<Gamepiece> testPiece2_;

public:
    GamemoveTest();

private Q_SLOTS:
    void initTestCase();
    void cleanupTestCase();
    void test_SpawnMove();
    void test_MoveMove();
    void test_TopMove();
};

GamemoveTest::GamemoveTest()
{
}

void GamemoveTest::initTestCase()
{
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
}

void GamemoveTest::test_SpawnMove()
{
    std::shared_ptr<GameState> testState = std::shared_ptr<GameState>(new GameState());

    GamemoveSpawnPiece moveSpawnMove(1, 0, Position(2,-1));

    std::shared_ptr<GameState> resultState = moveSpawnMove.ApplyOnGamestate(testState);
    resultState->RemovePile(Position(2, -1));
}

void GamemoveTest::test_MoveMove()
{
    std::shared_ptr<GameState> testState = std::shared_ptr<GameState>(new GameState());
    testState->AddGamepiece(testPiece1_, Position (0, 0));
    testState->AddGamepiece(testPiece2_, Position (1, 1));

    GamemoveMovePile moveMove(1, Position (0, 0), Position(1, 1));

    std::shared_ptr<GameState> resultState = moveMove.ApplyOnGamestate(testState);
    resultState->RemovePile(Position(1, 1));
}

void GamemoveTest::test_TopMove()
{
    std::shared_ptr<GameState> testState = std::shared_ptr<GameState>(new GameState());
    testState->AddGamepiece(testPiece1_, Position (0, 0));
    testState->AddGamepiece(testPiece2_, Position (1, 1));

    GamemoveMovePile moveMove(1, Position (0, 0), Position(1, 1));
    GamemoveMoveTop moveTopMove(1, Position (1, 1), Position(-1, -1));

    std::shared_ptr<GameState> resultState1 = moveMove.ApplyOnGamestate(testState);
    std::shared_ptr<GameState> resultState2 = moveTopMove.ApplyOnGamestate(resultState1);
    resultState2->RemovePile(Position(1, 1));
    resultState2->RemovePile(Position(-1, -1));
}

QTEST_APPLESS_MAIN(GamemoveTest)

#include "tst_gamemovetest.moc"
