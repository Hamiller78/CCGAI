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

#ifndef PYTHONSETUP_H
#define PYTHONSETUP_H

#include "Python.h"

#include <QString>

#include "exceptionplugin.h"

namespace ai {

class PythonSetup
{
private:
    QString pluginPath_{""};
    bool pythonInitialized_{false};
public:
    PythonSetup (PythonSetup const&) = delete;
    void operator=(PythonSetup const&) = delete;
    static PythonSetup& GetInstance();
    void SetPluginPath(QString newPluginPath);
private:
    PythonSetup(){}
};

} // namespace ai

#endif // PYTHONSETUP_H