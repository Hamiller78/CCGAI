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
    std::shared_ptr<Gamepiece> testPiece1_;
    std::shared_ptr<Gamepiece> testPiece2_;
    std::shared_ptr<Gamepiece> testPiece3_;
    std::shared_ptr<Gamepiece> testPiece4_;
    Pile *testPile1_;
    Pile *testPile2_;

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
    testPiece1_ = std::shared_ptr<Gamepiece>(new Gamepiece);
    testPiece2_ = std::shared_ptr<Gamepiece>(new Gamepiece);
    testPiece3_ = std::shared_ptr<Gamepiece>(new Gamepiece);
    testPiece4_ = std::shared_ptr<Gamepiece>(new Gamepiece);
    testPile1_ = new Pile;
    testPile2_ = new Pile;
}

void PileTest::cleanupTestCase()
{
    testPiece1_.reset();
    testPiece2_.reset();
    testPiece3_.reset();
    testPiece4_.reset();
    delete testPile1_;
    delete testPile2_;
}

void PileTest::testCase1()
{
    testPile1_->AddOnTop(testPiece1_);
    QVERIFY2(testPile1_->GetTopPiece() == testPiece1_, "Incorrect gamepiece on top of pile!");
    testPile1_->AddOnTop(testPiece2_);
    QVERIFY2(testPile1_->GetTopPiece() == testPiece2_, "Incorrect gamepiece on top of pile!");
    testPile2_->AddOnTop(testPiece3_);
    testPile2_->AddOnTop(testPiece4_);
    testPile2_->AddPile(*testPile1_);
    QVERIFY2(testPile2_->GetPilesize() == 4, "Combined pile has not correct size!");
    QVERIFY2(testPile2_->GetTopPiece() == testPiece2_, "Combined pile has not correct top piece!");
    std::shared_ptr<Gamepiece> checkPiece = testPile2_->PickupTopPiece();
    QVERIFY2(testPile2_->GetTopPiece() == testPiece1_, "Combined pile has not correct top piece after pickup!");
    QVERIFY2(checkPiece == testPiece2_, "Incorrect piece picked up!");
    testPile2_->AddToBottom(checkPiece);
    std::vector<std::shared_ptr<Gamepiece>> pieceList = testPile2_->GetPieceVector();
    QVERIFY2(pieceList[0] == testPiece2_, "Error in piece order in vector, index 0!");
    QVERIFY2(pieceList[1] == testPiece3_, "Error in piece order in vector, index 1!");
    QVERIFY2(pieceList[2] == testPiece4_, "Error in piece order in vector, index 2!");
    QVERIFY2(pieceList[3] == testPiece1_, "Error in piece order in vector, index 3!");
}

QTEST_APPLESS_MAIN(PileTest)

#include "tst_piletest.moc"
