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

// test game logic is in mock classes:
// - only Pointcounter(0) of GameStates is used
// - Gamemovemock alters the point value
// - Rulebookmock provides only two sets of moves:
//   - Even Gamestates: +4/-2/+1
//   - Odd Gamestates: -6/+2
// - Playeragentmock uses Pointcounter(0) as rating value
// - Win condition: >20 points: player 1, <-20 points: player 2
// -> Even states lead to player 1 winning, odd states to player 2 winning
// - Player 2 will have to use the +1 move once to get the game on the odd states
// - Player 2 should only see this, when the move depth its looking into is at least 3

using namespace game;

class GameloopTest : public QObject
{
    Q_OBJECT

private:
    std::shared_ptr<Rulebook> testRulebook_;

public:
    GameloopTest();
    ~GameloopTest();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_RunGameAiDepth1();
    void test_RunGameAiDepth3();

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
}

void GameloopTest::cleanupTestCase()
{
    testRulebook_.reset();
}

void GameloopTest::test_RunGameAiDepth1()
{
    PlayerAgentMock testPlayer1(1);
    PlayerAgentMock testPlayer2(1);
    GameState testStartState;
    Gameloop testLoop(*testRulebook_, testPlayer1, testPlayer2);

    int Winner = testLoop_->RunGame(testStartState);
    QVERIFY2(Winner == 1, "The winner of the game was not player 1!");
}

void GameloopTest::test_RunGameAiDepth3()
{
    PlayerAgentMock testPlayer1(3);
    PlayerAgentMock testPlayer2(3);
    GameState testStartState;
    Gameloop testLoop(*testRulebook_, testPlayer1, testPlayer2);

    int Winner = testLoop_->RunGame(testStartState);
    QVERIFY2(Winner == 2, "The winner of the game was not player 2!");
}

QTEST_APPLESS_MAIN(GameloopTest)

#include "tst_gamelooptest.moc"
