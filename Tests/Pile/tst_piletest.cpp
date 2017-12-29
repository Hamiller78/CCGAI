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

#include "../../Prototype/gamepiece.h"
#include "../../Prototype/pile.h"

using namespace game;

class PileTest : public QObject
{
    Q_OBJECT

private:
    std::shared_ptr<Gamepiece> testPiece1;
    std::shared_ptr<Gamepiece> testPiece2;
    std::shared_ptr<Gamepiece> testPiece3;
    std::shared_ptr<Gamepiece> testPiece4;
    Pile *testPile1;
    Pile *testPile2;

public:
    PileTest();

private Q_SLOTS:
    void initTestCase();
    void cleanupTestCase();
    void testCase1();
};

PileTest::PileTest()
{
}

void PileTest::initTestCase()
{
    testPiece1 = std::shared_ptr<Gamepiece>(new Gamepiece);
    testPiece2 = std::shared_ptr<Gamepiece>(new Gamepiece);
    testPiece3 = std::shared_ptr<Gamepiece>(new Gamepiece);
    testPiece4 = std::shared_ptr<Gamepiece>(new Gamepiece);
    testPile1 = new Pile;
    testPile2 = new Pile;
}

void PileTest::cleanupTestCase()
{
    testPiece1.reset();
    testPiece2.reset();
    testPiece3.reset();
    testPiece4.reset();
    delete testPile1;
    delete testPile2;
}

void PileTest::testCase1()
{
    testPile1->AddOnTop(testPiece1);
    QVERIFY2(testPile1->GetTopPiece() == testPiece1, "Incorrect gamepiece on top of pile!");
    testPile1->AddOnTop(testPiece2);
    QVERIFY2(testPile1->GetTopPiece() == testPiece2, "Incorrect gamepiece on top of pile!");
    testPile2->AddOnTop(testPiece3);
    testPile2->AddOnTop(testPiece4);
    testPile2->AddPile(*testPile1);
    QVERIFY2(testPile2->GetPilesize() == 4, "Combined pile has not correct size!");
    QVERIFY2(testPile2->GetTopPiece() == testPiece2, "Combined pile has not correct top piece!");
    std::shared_ptr<Gamepiece> checkPiece = testPile2->PickupTopPiece();
    QVERIFY2(testPile2->GetTopPiece() == testPiece1, "Combined pile has not correct top piece after pickup!");
    QVERIFY2(checkPiece == testPiece2, "Incorrect piece picked up!");
    testPile2->AddToBottom(checkPiece);
    std::vector<std::shared_ptr<Gamepiece>> pieceList = testPile2->GetPieceVector();
    QVERIFY2(pieceList[0] == testPiece2, "Error in piece order in vector, index 0!");
    QVERIFY2(pieceList[1] == testPiece3, "Error in piece order in vector, index 1!");
    QVERIFY2(pieceList[2] == testPiece4, "Error in piece order in vector, index 2!");
    QVERIFY2(pieceList[3] == testPiece1, "Error in piece order in vector, index 3!");
}

QTEST_APPLESS_MAIN(PileTest)

#include "tst_piletest.moc"
