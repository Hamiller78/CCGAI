/* Copyright (c) 2018 Torben Kneesch

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

#include "../../Prototype/gameloop.h"
#include "../../Prototype/gamestate.h"
#include "../../Prototype/playeragentmock.h"
#include "../../Prototype/rulebookmock.h"

#include <QtTest>

using namespace game;

class GameloopTest : public QObject
{
    Q_OBJECT

private:
    std::shared_ptr<Gameloop> testLoop_;
    std::shared_ptr<Rulebook> testRulebook_;
    std::shared_ptr<PlayerAgent> testPlayExpert_;
    std::shared_ptr<GameState> startState_;

public:
    GameloopTest();
    ~GameloopTest();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_RunGame();

};

GameloopTest::GameloopTest()
{

}

GameloopTest::~GameloopTest()
{

}

void GameloopTest::initTestCase()
{
    testRulebook_ = std::shared_ptr<Rulebook>(new RulebookMock());
    testPlayExpert_ = std::shared_ptr<PlayerAgent>(new PlayerAgentMock());
    testLoop_ = std::shared_ptr<Gameloop>(new Gameloop(*testRulebook_, *testPlayExpert_));
    startState_ = std::shared_ptr<GameState>(new GameState());
}

void GameloopTest::cleanupTestCase()
{
    testLoop_.reset();
    startState_.reset();
    testPlayExpert_.reset();
    testRulebook_.reset();
}

void GameloopTest::test_RunGame()
{
    // TODO: Mock objects should check that the expected moves are executed
//    int Winner = testLoop_->RunGame(*startState_);
//    QVERIFY2(Winner == 1, "The winner of the game was not player 1!");
}

QTEST_APPLESS_MAIN(GameloopTest)

#include "tst_gamelooptest.moc"
