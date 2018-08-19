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

#include "../../Prototype/deck.h"
#include "../../Prototype/gameloop.h"
#include "../../Prototype/rulebookmock.h"

#include <QtTest>

using namespace game;

class GameloopTest : public QObject
{
    Q_OBJECT

private:
    Gameloop *testLoop_;
    plugin::Deck *deck1_;
    plugin::Deck *deck2_;
    RulebookMock *testRulebook_;

public:
    GameloopTest();
    ~GameloopTest();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_case1();

};

GameloopTest::GameloopTest()
{

}

GameloopTest::~GameloopTest()
{

}

void GameloopTest::initTestCase()
{
    testRulebook_ = new RulebookMock();
    testLoop_ = new Gameloop(*testRulebook_);
    deck1_ = new plugin::Deck();
    deck2_ = new plugin::Deck();
    deck1_->LoadDecklistFromTxt("../../../CCGAI/Tests/testdata/plugins/duelgame/decks/deck1.txt");
    deck2_->LoadDecklistFromTxt("../../../CCGAI/Tests/testdata/plugins/duelgame/decks/deck1.txt");
}

void GameloopTest::cleanupTestCase()
{
    delete testLoop_;
    delete testRulebook_;
}

void GameloopTest::test_case1()
{
    testRulebook_->SetupGame(*deck1_, *deck2_);
}

QTEST_APPLESS_MAIN(GameloopTest)

#include "tst_gamelooptest.moc"
