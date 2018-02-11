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

#include "scriptwrapper.h"

namespace ai {

ScriptWrapper::ScriptWrapper()
{

}

PyObject *ScriptWrapper::LoadFunction(QString functionName)
{
    // TODO: make exception class for script problems
    if (pyModule_ == nullptr)
    {
        throw std::exception();
    }
    PyObject *pFunction = PyObject_GetAttrString(pModule, functionName.toStdString().c_str());
    if (pFunction == nullptr || !PyCallableCheck(pFunction))
    {
        throw std::expection();
    }
    return pFunction;
}

ScriptWrapper::LoadModule(QString moduleName)
{
    pyModule_ = PyImport_ImportModule(moduleName.toStdString().c_str());
    if (pyModule_ == nullptr)
    {
        // TODO: Exceptions for scripts
        throw std::exception();
    }
}

} // namespace ai
