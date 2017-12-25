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
    testPlugin->loadPlugin("../../../CCGAI/Tests/testdata/plugins/duelgame");
}

QTEST_APPLESS_MAIN(PluginTest)

#include "tst_plugintest.moc"
