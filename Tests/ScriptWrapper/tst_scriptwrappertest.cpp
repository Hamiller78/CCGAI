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

#include <iostream>

#include <string>
#include <QString>
#include <QtTest>

using namespace python;

class ScriptWrapperTest : public QObject
{
    Q_OBJECT

private:
    ScriptWrapper testWrapper;

public:
    ScriptWrapperTest();

private Q_SLOTS:
    void initTestCase();
    void cleanupTestCase();
    void test_FunctionCall();
    void test_ModuleNotFoundException();
    void test_LoadFunction();
};

ScriptWrapperTest::ScriptWrapperTest()
{
}

void ScriptWrapperTest::initTestCase()
{
    PythonSetup::GetInstance()
            .OpenPython("../../../CCGAI/Tests/testdata/plugins/duelgame");
}

void ScriptWrapperTest::cleanupTestCase()
{
    PythonSetup::GetInstance().ClosePython();
}

void ScriptWrapperTest::test_FunctionCall()
{
    int errorcode;

    PyObject *pModule = PyImport_ImportModule("Square");
    QVERIFY2(pModule != nullptr, "Module not loaded properly!");
    PyObject *pScript = PyObject_GetAttrString(pModule, "square");
    QVERIFY2(pScript && PyCallable_Check(pScript), "Function not loaded properly!");
    Py_DECREF(pModule);

    PyObject *pArgs = PyTuple_New(1);
    PyObject *pParameter = PyLong_FromLong(16);
    errorcode = PyTuple_SetItem(pArgs, 0, pParameter);
    QVERIFY2(errorcode == 0, "Setting argument for Python call failed!");
    PyObject *pValue = PyObject_CallObject(pScript, pArgs);
    long returnValue = PyLong_AsLong(pValue);
    QVERIFY2(returnValue == 256, "Failure");

    Py_DECREF(pValue);
    Py_DECREF(pArgs);
    Py_DECREF(pScript);
    Py_DECREF(pModule);
}

void ScriptWrapperTest::test_ModuleNotFoundException()
{
    ScriptWrapper failWrapper;
    QVERIFY_EXCEPTION_THROWN(failWrapper.LoadModule("not_existing"),
                             ExceptionScriptWrapper);
}

void ScriptWrapperTest::test_LoadFunction()
{
    testWrapper.LoadModule("Test");
    QVERIFY_EXCEPTION_THROWN(testWrapper.LoadFunction("not_existing"),
                             ExceptionScriptWrapper);
    PyObject *extensionScript = testWrapper.LoadFunction("test_extension");
    PyObject *pValue = PyObject_CallObject(extensionScript, nullptr);
    long returnValue = PyLong_AsLong(pValue);
    QVERIFY2(returnValue == 7, "Failure");
    Py_DECREF(pValue);
    Py_DECREF(extensionScript);
}

QTEST_APPLESS_MAIN(ScriptWrapperTest)

#include "tst_scriptwrappertest.moc"
