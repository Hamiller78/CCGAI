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

#include <cmath>
#include "Python.h"

#include "../../Prototype/pythonsetup.h"

#include <QString>
#include <QtTest>

using namespace ai;

class PythonSetupTest : public QObject
{
    Q_OBJECT

public:
    PythonSetupTest();

private Q_SLOTS:
    void initTestCase();
    void cleanupTestCase();
    void testCase1();
};

PythonSetupTest::PythonSetupTest()
{
}

void PythonSetupTest::initTestCase()
{
    QString pluginPath = "../../../CCGAI/Tests/testdata/plugins/duelgame";
    PythonSetup::GetInstance().SetPluginPathAndReopenPython(pluginPath);
}

void PythonSetupTest::cleanupTestCase()
{
    PythonSetup::GetInstance().ClosePython();
}

void PythonSetupTest::testCase1()
{
    PyObject *pModule = PyImport_ImportModule("Test");
    QVERIFY2(pModule != nullptr, "Module not loaded properly!");
    PyObject *pScript = PyObject_GetAttrString(pModule, "tripler");
    QVERIFY2(pScript && PyCallable_Check(pScript), "Function not loaded properly!");

    PyObject *pArgs = PyTuple_New(1);
    PyObject *pParameter = PyLong_FromLong(16);
    int errorcode = PyTuple_SetItem(pArgs, 0, pParameter);
    QVERIFY2(errorcode == 0, "Setting argument for Python call failed!");
    PyObject *pValue = PyObject_CallObject(pScript, pArgs);
    long returnValue = PyLong_AsLong(pValue);
    QVERIFY2(returnValue == 48, "Failure");
}

QTEST_APPLESS_MAIN(PythonSetupTest)

#include "tst_pythonsetuptest.moc"
