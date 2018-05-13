/* Copyright (c) 2017,2018 Torben Kneesch

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

void Plugin::LoadPlugin(const QString &pluginDirName)
{
    try
    {
        CheckDirExists(pluginDirName);
        QStringList setListFilenames = GetSetListFilenames(pluginDirName);
        QStringList cardData = LoadCardData(pluginDirName, setListFilenames);
        LoadCardBack(pluginDirName);
        Cardpool::GetInstance().SetPool(cardData);
    }
    catch (ExceptionPlugin &e)
    {
        throw;
    }
}

void Plugin::CheckDirExists(const QString &dirName) const
{
    QDir pluginDir(dirName);
    if (!pluginDir.exists())
    {
        throw ExceptionPlugin("Plugin directory doesn't exist: " + dirName.toStdString());
    }
}

void Plugin::CheckFileExists(const QString &fileName) const
{
    if (!QFile::exists(fileName))
    {
        throw ExceptionPlugin("Plugin file not found: " + fileName.toStdString());
    }
}

void Plugin::LoadGameStructure(const QString &dirName) const
{
    QString fileName = QDir::cleanPath(dirName + "/ai/gamestructure.txt");
    CheckFileExists(fileName);
    QFile gamestructureFile(fileName);
    if (!gamestructureFile.open(QIODevice::ReadOnly))
    {
        throw ExceptionPlugin("AI gamestructure file couldn't be opened: " + fileName.toStdString());
    }
    QTextStream fileContent(&gamestructureFile);
    QString dataTable = fileContent.readAll();
    QStringList dataLines;
    dataLines.append(dataTable.split(QRegExp("[\r\n]"), QString::SkipEmptyParts));
    gamestructureFile.close();
}

QStringList Plugin::GetSetListFilenames(const QString &pluginDirName) const
{
    QString fileName = QDir::cleanPath(pluginDirName + "/" + "setlist.txt");
    CheckFileExists(fileName);
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

void Plugin::LoadCardBack(const QString &pluginDirName)
{

}

QStringList Plugin::LoadCardData(const QString &pluginDirName, const QStringList &setListFilenames)
{
    QStringList dataLines;
    for (int i = 0; i < setListFilenames.size(); i++)
    {
        QString fileName
          = QDir::cleanPath(pluginDirName + "/" + QString("sets") + "/" + setListFilenames[i]);
        CheckFileExists(fileName);
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
