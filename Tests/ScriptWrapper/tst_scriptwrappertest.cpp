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
#include <iostream>
#include "Python.h"

#include <string>
#include <QString>
#include <QtTest>

class ScriptWrapperTest : public QObject
{
    Q_OBJECT

public:
    ScriptWrapperTest();

private Q_SLOTS:
    void initTestCase();
    void cleanupTestCase();
    void testCase1();
    void testCase2();
};

ScriptWrapperTest::ScriptWrapperTest()
{
}

void ScriptWrapperTest::initTestCase()
{
    std::cout << "Setting path for Python.\n";
    Py_SetPath(L"../../../CCGAI/Tests/testdata/PythonLib;"
               + L"../../../CCGAI/Tests/testdata/plugins/duelgame/ai");
    std::cout << "Path is set!\n";
    Py_Initialize();
}

void ScriptWrapperTest::cleanupTestCase()
{
    QVERIFY2(Py_FinalizeEx() == 0, "Python unloading reported a problem!");
}

void ScriptWrapperTest::testCase1()
{
    int errorcode;

    PyObject *pModule = PyImport_ImportModule("Square");
    QVERIFY2(pModule != nullptr, "Module not loaded properly!");
    PyObject *pScript = PyObject_GetAttrString(pModule, "square");
    QVERIFY2(pScript && PyCallable_Check(pScript), "Function not loaded properly!");

    PyObject *pArgs = PyTuple_New(1);
    PyObject *pParameter = PyLong_FromLong(16);
    errorcode = PyTuple_SetItem(pArgs, 0, pParameter);
    QVERIFY2(errorcode == 0, "Setting argument for Python call failed!");
    PyObject *pValue = PyObject_CallObject(pScript, pArgs);   // <- causes crash!!!
    long returnValue = PyLong_AsLong(pValue);
    std::cout << "Square of 16: " << returnValue << "\n";
    QVERIFY2(returnValue == 256, "Failure");
}

void ScriptWrapperTest::testCase2()
{
    int errorcode;

    PyObject *pModule = PyImport_ImportModule("Test");
    QVERIFY2(pModule != nullptr, "Module not loaded properly!");
    PyObject *pScript = PyObject_GetAttrString(pModule, "tripler");
    QVERIFY2(pScript && PyCallable_Check(pScript), "Function not loaded properly!");

    PyObject *pArgs = PyTuple_New(1);
    PyObject *pParameter = PyLong_FromLong(16);
    errorcode = PyTuple_SetItem(pArgs, 0, pParameter);
    QVERIFY2(errorcode == 0, "Setting argument for Python call failed!");
    PyObject *pValue = PyObject_CallObject(pScript, pArgs);   // <- causes crash!!!
    long returnValue = PyLong_AsLong(pValue);
    std::cout << "Triple of 16: " << returnValue << "\n";
    QVERIFY2(returnValue == 48, "Failure");
}


QTEST_APPLESS_MAIN(ScriptWrapperTest)

#include "tst_scriptwrappertest.moc"
