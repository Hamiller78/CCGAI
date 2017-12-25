/* Copyright (c) 2017 Torben Kneesch

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

#include "plugin.h"

namespace plugin {

Plugin::Plugin()
{

}

void Plugin::loadPlugin(const QString &pluginDirName)
{
    try
    {
        checkDirExists(pluginDirName);
        QStringList setListFilenames = getSetListFilenames(pluginDirName);
        QStringList cardData = loadCardData(pluginDirName, setListFilenames);
        loadCardBack(pluginDirName);
        Cardpool::setPool(cardData);
    }
    catch (ExceptionPlugin &e)
    {
        throw;
    }
}

void Plugin::checkDirExists(const QString &pluginDirName) const
{
    QDir pluginDir(pluginDirName);
    if (!pluginDir.exists())
    {
        throw ExceptionPlugin("Plugin directory doesn't exist!");
    }
}

void Plugin::checkFileExists(const QString &fileName) const
{
    if (!QFile::exists(fileName))
    {
        throw ExceptionPlugin("Plugin file not found: " + fileName.toStdString());
    }
}

QStringList Plugin::getSetListFilenames(const QString &pluginDirName) const
{
    QString fileName = QDir::cleanPath(pluginDirName + "/" + "setlist.txt");
    checkFileExists(fileName);
    QFile setListFile(fileName);

    QStringList setNames;
    if (setListFile.open(QIODevice::ReadWrite | QIODevice::Text))
    {
    //read first lines from text file
        QTextStream setListStream(&setListFile);
        QString setLine = setListStream.readLine();
        if (setLine != "")
        {
            int setCount = setLine.toInt();
            for (int i = 1; i <= setCount; i++)
            {
                setNames << setListStream.readLine();
            }
        }
        setListFile.close();
    }
    else
    {
        setNames << QString("carddata.txt");
    }
    return setNames;
}

void Plugin::loadCardBack(const QString &pluginDirName)
{

}

QStringList Plugin::loadCardData(const QString &pluginDirName, const QStringList &setListFilenames)
{
    QStringList dataLines;
    for (int i = 0; i < setListFilenames.size(); i++)
    {
        QString fileName
          = QDir::cleanPath(pluginDirName + "/" + QString("sets") + "/" + setListFilenames[i]);
        checkFileExists(fileName);
        QFile cardListFile(fileName);
        if (!cardListFile.open(QIODevice::ReadOnly))
        {
            throw ExceptionPlugin("Carddata file couldn't be opened: " + fileName.toStdString());
        }

        QTextStream fileContent(&cardListFile);
        QString dataTable = fileContent.readAll();
        dataLines.append(dataTable.split(QRegExp("[\r\n]"), QString::SkipEmptyParts));
        cardListFile.close();
    }
    return dataLines;
}

} // namespace plugin
