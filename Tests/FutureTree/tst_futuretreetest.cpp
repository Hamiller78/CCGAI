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

#include <QtTest>

// add necessary includes here
#include "../../Prototype/futuretree.h"
#include "../../Prototype/gamemovemock.h"
#include "../../Prototype/gamestate.h"
#include "../../Prototype/stateanalyzermock.h"

using namespace ai;

class FutureTreeTest : public QObject
{
    Q_OBJECT

public:
    FutureTreeTest();
    ~FutureTreeTest();

private slots:
    void test_turndepth1();

};

FutureTreeTest::FutureTreeTest()
{

}

FutureTreeTest::~FutureTreeTest()
{

}

void FutureTreeTest::test_turndepth1()
{
    StateAnalyzer *testAnalyzer = new StateAnalyzerMock();
    FutureTree testTree = FutureTree(*testAnalyzer);
    std::shared_ptr<game::GameState> startStatePtr
            = std::shared_ptr<game::GameState>(new game::GameState());

    testTree.SetDepth(100);

    std::shared_ptr<game::Gamemove> bestMove = testTree.FindBestMove(startStatePtr, 1);
    std::shared_ptr<game::GamemoveMock> bestMoveMock
            = std::dynamic_pointer_cast<game::GamemoveMock>(bestMove);

    QVERIFY2(bestMoveMock->GetMoveNumber() ==  4, "Best move is not the expected one.");

    delete testAnalyzer;
}

QTEST_APPLESS_MAIN(FutureTreeTest)

#include "tst_futuretreetest.moc"
