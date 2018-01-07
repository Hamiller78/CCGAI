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

#include <QString>
#include <QtTest>

using namespace plugin;

class DeckTest : public QObject
{
    Q_OBJECT


private:
   Deck *testDeck_;

public:
    DeckTest();

private Q_SLOTS:
    void initTestCase();
    void cleanupTestCase();
    void testCase1();
};

DeckTest::DeckTest()
{
}

void DeckTest::initTestCase()
{
        testDeck_ = new Deck;
}

void DeckTest::cleanupTestCase()
{
    delete testDeck_;
}

void DeckTest::testCase1()
{
    testDeck_->LoadDecklistFromTxt("../../../CCGAI/Tests/testdata/plugins/duelgame/decks/deck1.txt");
    QStringList deckNames = testDeck_->GetDeckNames();
    std::vector<QStringList> testDecks = testDeck_->GetDeckLists();
    QStringList drawDeckList = testDecks[0];
    QVERIFY2(deckNames[0] == "Draw Deck", "Deck name of draw deck wrong!");
    QVERIFY2(drawDeckList.size() == 20, "Size of deck is not equal 20!");
    QVERIFY2(drawDeckList[0] == "Rookie", "Slot 0 of deck does not contain Rookie.");
    QVERIFY2(drawDeckList[5] == "Rookie", "Slot 5 of deck does not contain Rookie.");
    QVERIFY2(drawDeckList[9] == "Rookie", "Slot 0 of deck does not contain Rookie.");
    QVERIFY2(drawDeckList[10] == "Veteran", "Slot 10 of deck does not contain Veteran.");
    QVERIFY2(drawDeckList[19] == "Veteran", "Slot 19 of deck does not contain Veteran.");
}

QTEST_APPLESS_MAIN(DeckTest)

#include "tst_decktest.moc"
