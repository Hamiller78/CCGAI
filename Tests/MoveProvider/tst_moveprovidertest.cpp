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

#include "../../Prototype/pythonsetup.h"
#include "../../Prototype/scriptwrapper.h"
#include "../../Prototype/moveprovider.h"

#include <QString>
#include <QtTest>

using namespace python;

class MoveProviderTest : public QObject
{
    Q_OBJECT

private:
    MoveProvider *testWrapper;
public:
    MoveProviderTest();

private Q_SLOTS:
    void initTestCase();
    void cleanupTestCase();
    void test_GetMoves();
    void test_ExceptionOnErrorCode();
};

MoveProviderTest::MoveProviderTest()
{
}

void MoveProviderTest::initTestCase()
{
    PythonSetup::GetInstance()
            .OpenPython("../../../CCGAI/Tests/testdata/plugins/duelgame");
    testWrapper = new MoveProvider;
}

void MoveProviderTest::cleanupTestCase()
{
    delete testWrapper;
    PythonSetup::GetInstance().ClosePython();
}

void MoveProviderTest::test_GetMoves()
{
    testWrapper->LoadModule("Test");
    testWrapper->GetMoves(0);
}

void MoveProviderTest::test_ExceptionOnErrorCode()
{
    QVERIFY_EXCEPTION_THROWN(testWrapper->GetMoves(1),
                             ExceptionScriptWrapper);
}

QTEST_APPLESS_MAIN(MoveProviderTest)

#include "tst_moveprovidertest.moc"
