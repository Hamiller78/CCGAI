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

#ifndef PYTHONEXTENSION_H
#define PYTHONEXTENSION_H

#include <cmath>
#include "Python.h"

namespace python {

PyObject *PyGetInfo(PyObject *self, PyObject *args);

static PyMethodDef ccgaiModuleMethods[]
    {
        {"getinfo", PyGetInfo, METH_VARARGS, "Returns info about CCGAI module"},
        {nullptr, nullptr, 0, nullptr}
    };

static PyModuleDef ccgaiModuleDef =
{PyModuleDef_HEAD_INIT, "ccgai", "Extension to access data within CCGAI core program",
    -1, ccgaiModuleMethods, nullptr, nullptr, nullptr, nullptr
};

PyMODINIT_FUNC PyInitCcgai(void);

/*
class PythonExtension
{
private:
//    constexpr static const char* infoString{"CCGAI Python module V0.0"};
public:
    PythonExtension();
private:
/*    static PyMethodDef ccgaiModuleMethods[]
    {
        {"getinfo", (PyCFunction)PyGetInfo, METH_VARARGS, "Returns info about CCGAI module"},
        {nullptr, nullptr, 0, nullptr}
    };
    static PyModuleDef ccgaiModuleDef =
    {PyModuleDef_HEAD_INIT, "ccgai", "Extension to access data within CCGAI core program",
        -1, ccgaiModuleMethods, nullptr, nullptr, nullptr, nullptr
    };
};

*/

} // namespace python

#endif // PYTHONEXTENSION_H
