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

#include "../../Prototype/plugin.h"

#include <QString>
#include <QtTest>

using namespace plugin;

class PluginTest : public QObject
{
    Q_OBJECT

private:
    Plugin *testPlugin;

public:
    PluginTest();

private Q_SLOTS:
    void initTestCase();
    void cleanupTestCase();
    void testCase1();
    void testCase2();
};

PluginTest::PluginTest()
{
}

void PluginTest::initTestCase()
{
    testPlugin = new Plugin;
}

void PluginTest::cleanupTestCase()
{
    delete testPlugin;
}

void PluginTest::testCase1()
{
    testPlugin->LoadPlugin("../../../CCGAI/Tests/testdata/plugins/duelgame");
    Cardpool &testPool = Cardpool::GetInstance();
    std::shared_ptr<game::Card> testCard = testPool.MakeCard(0);
    QString cardName = testCard->GetTraitText("Name");
    QVERIFY2(cardName == QString("Rookie"), "Name of card with index 0 is wrong!");
    QString cardImage = testCard->GetTraitText("Imagefile");
    QVERIFY2(cardImage == QString("Rookie.jpeg"), "Imagefile of card with index 0 is wrong!");
    QString cardAttack = testCard->GetTraitText("Attack");
    QVERIFY2(cardAttack == QString("1"), "Attack of card with index 0 is wrong!");
    QString cardDefense = testCard->GetTraitText("Defense");
    QVERIFY2(cardDefense == QString("1"), "Defense of card with index 0 is wrong!");

    testCard = testPool.MakeCard(1);
    cardName = testCard->GetTraitText("Name");
    QVERIFY2(cardName == QString("Veteran"), "Name of card with index 1 is wrong!");
    cardImage = testCard->GetTraitText("Imagefile");
    QVERIFY2(cardImage == QString("Veteran.jpeg"), "Imagefile of card with index 1 is wrong!");
    cardAttack = testCard->GetTraitText("Attack");
    QVERIFY2(cardAttack == QString("2"), "Attack of card with index 1 is wrong!");
    cardDefense = testCard->GetTraitText("Defense");
    QVERIFY2(cardDefense == QString("2"), "Defense of card with index 1 is wrong!");

    testCard = testPool.MakeCard("Rookie");
    cardName = testCard->GetTraitText("Name");
    QVERIFY2(cardName == QString("Rookie"), "Name of card with title Rookie is wrong!");
}

void PluginTest::testCase2()
{
    QVERIFY_EXCEPTION_THROWN(testPlugin->LoadPlugin("../../../CCGAI/Tests/testdata/not_existing"),
                             ExceptionPlugin);
}

QTEST_APPLESS_MAIN(PluginTest)

#include "tst_plugintest.moc"
