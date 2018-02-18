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

#ifndef MOVEPROVIDER_H
#define MOVEPROVIDER_H

#include <QObject>
#include "scriptwrapper.h"

namespace python {

class MoveProvider : public ScriptWrapper
{
    // TODO: methods to connect and disconnect slots
    // TODO: automatically load GetMoves function in Python script after loading of module
    // TODO: implement GetMoves method, parameter conversion from C++ to Python
private:
    PyObject *getMoveScript_;
public:
    MoveProvider();
    void LoadModule(QString moduleName) override;
public Q_SLOTS:
    void GetMoves(int gameStateNumber);
};

} // namespace python

#endif // MOVEPROVIDER_H
