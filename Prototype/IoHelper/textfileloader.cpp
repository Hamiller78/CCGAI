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

#include "textfileloader.h"

namespace iohelper {

QStringList TextfileLoader::FromFilename(const QString& filePath) const
{
    if (!QFile::exists(filePath))
    {
        throw new IoException("File not found: " + filePath.toStdString());
    }

    QFile textFile(filePath);
    if (!textFile.open(QIODevice::ReadOnly))
    {
        throw IoException("Text file couldn't be opened: " + filePath.toStdString());
    }

    QTextStream fileContent(&textFile);
    QString dataTable = fileContent.readAll();
    textFile.close();

    return dataTable.split(QRegExp("[\r\n]"), QString::SkipEmptyParts);
}

void TextfileLoader::CheckDirExists(const QString &dirName) const
{
    QDir pluginDir(dirName);
    if (!pluginDir.exists())
    {
        throw IoException("Directory doesn't exist: " + dirName.toStdString());
    }
}

} // namespace iohelper
