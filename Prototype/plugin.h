/* Copyright (c) 2017-2020 Torben Kneesch

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

#ifndef PLUGIN_H
#define PLUGIN_H

#include <stdexcept>

#include <QDir>
#include <QFile>
#include <QString>
#include <QTextStream>

#include "cardpool.h"
#include "exceptionplugin.h"
#include "iohelper/ioexception.h"
#include "iohelper/textfileloader.h"

namespace plugin {

// class to load information from a LackeyCCG plugin

class Plugin
{
private:
    QString pluginDirPath_;
public:
    Plugin(const iohelper::TextfileLoader& fileLoader) : fileLoader_(fileLoader){}
    void LoadPlugin(const QString& pluginDirName);
private:
    void CheckDirExists(const QString& pluginDirName) const;
    void LoadGameStructure(const QString& dirName) const;
    QStringList GetSetListFilenames(const QString& dirName) const;
    void LoadCardBack(const QString& pluginDirName);
    QStringList LoadCardData(const QString& pluginDirName, const QStringList& setListFilenames);

    const iohelper::TextfileLoader fileLoader_;
};

} // namespace plugin

#endif // PLUGIN_H
