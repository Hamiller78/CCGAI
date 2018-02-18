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

#include "moveprovider.h"

namespace python {

MoveProvider::MoveProvider()
{

}

void MoveProvider::LoadModule(QString moduleName)
{
    ScriptWrapper::LoadModule(moduleName);
    getMoveScript_ = LoadFunction("add_moves");
}

void MoveProvider::GetMoves(int gameStateNumber)
{
    int errorcode;
    PyObject *pArgs = PyTuple_New(1);
    PyObject *pParameter = PyLong_FromLong(gameStateNumber);
    errorcode = PyTuple_SetItem(pArgs, 0, pParameter);

    PyObject *pReturnValue = PyObject_CallObject(getMoveScript_, pArgs);

    errorcode = PyLong_AsLong(pReturnValue);
    if (errorcode != 0)
    {
        throw ExceptionScriptWrapper("Python script returns error code: " + std::to_string(errorcode));
    }
}

} // namespace python
