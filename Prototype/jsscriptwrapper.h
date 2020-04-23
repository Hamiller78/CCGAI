/* Copyright (c) 2020 Torben Kneesch

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
#ifndef JSSCRIPTWRAPPER_H
#define JSSCRIPTWRAPPER_H

#include <QCoreApplication>
#include <QJSEngine>

#include "iscriptwrapper.h"

namespace scripting {

class JSScriptWrapper : public IScriptWrapper
{
public:
    JSScriptWrapper(){}
    ~JSScriptWrapper() override {};

    static void Init() {jsEnginePtr_ = std::unique_ptr<QJSEngine>(new QJSEngine());}

    virtual void LoadScriptFile(const QString& filePath) override;
    virtual int ExecuteString(const QString& script) override;

private:
    static std::unique_ptr<QJSEngine> jsEnginePtr_;
};

} // namespace scripting

#endif // JSSCRIPTWRAPPER_H
