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

#include "../../Prototype/gamestate.h"

#include <QtTest>

using namespace game;

class GameStateTest : public QObject
{
    Q_OBJECT

public:
    GameStateTest();
    ~GameStateTest();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_SetNumberOfPointCounters();
    void test_ManipulatePoints();

};

GameStateTest::GameStateTest()
{

}

GameStateTest::~GameStateTest()
{

}

void GameStateTest::initTestCase()
{

}

void GameStateTest::cleanupTestCase()
{

}

void GameStateTest::test_SetNumberOfPointCounters()
{
    QVERIFY2(GameState::GetNumberOfPointCounters() == 2, "Default number of pointers is not 2.");
    GameState::SetNumberOfPointCounters(4);
    QVERIFY2(GameState::GetNumberOfPointCounters() == 4
             , "Default number of pointers is not 4 after setting.");
    GameState::SetNumberOfPointCounters(2);
}

void GameStateTest::test_ManipulatePoints()
{
    GameState::SetNumberOfPointCounters(4);
    GameState testState;
    testState.SetPoints(3, 42);
    QVERIFY2(testState.GetPoints(3) == 42, "Points of index 3 not read correctly after setting.");
    testState.AlterPoints(3, 10);
    QVERIFY2(testState.GetPoints(3) == 52
             , "Points of index 3 not read correctly after increasing.");
    testState.AlterPoints(3, -20);
    QVERIFY2(testState.GetPoints(3) == 32
             , "Points of index 3 not read correctly after decreasing.");
    GameState::SetNumberOfPointCounters(2);
}

QTEST_APPLESS_MAIN(GameStateTest)

#include "tst_gamestatetest.moc"
