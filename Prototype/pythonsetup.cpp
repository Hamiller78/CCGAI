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

#include "pythonsetup.h"

namespace python {

PythonSetup &PythonSetup::GetInstance()
{
    static PythonSetup instance;
    return instance;
}

void PythonSetup::ClosePython()
{
    int errorCode = Py_FinalizeEx();
    if (errorCode != 0)
    {
        throw ExceptionScriptWrapper("Python shutdown failed!");
    }
}

void PythonSetup::SetPluginPathAndReopenPython(QString newPluginPath)
{
    if (newPluginPath != pluginPath_ && !newPluginPath.isEmpty())
    {
        pluginPath_ = newPluginPath;
        ClosePython();
        QString pluginAiPath = "../../../CCGAI/Tests/testdata/PythonLib";
        pluginAiPath += ";" + newPluginPath + "/ai";
        Py_SetPath(pluginAiPath.toStdWString().c_str());
        int errorcode = PyImport_AppendInittab("ccgai", &PyInitCcgai);
        if (errorcode == -1)
        {
            throw ExceptionScriptWrapper("CCGAI Python extension initialization failed!");
        }
        Py_Initialize();
    }
}

} // namespace python
