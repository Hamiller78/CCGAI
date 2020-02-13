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

#include "plugin.h"

namespace plugin {

// loads set lists, card data and card back from plugin directories and sets the card pool
void Plugin::LoadPlugin(const QString &pluginDirName)
{
    try
    {
        CheckDirExists(pluginDirName);
        QStringList setListFilenames = GetSetListFilenames(pluginDirName);
        QStringList cardData = LoadCardData(pluginDirName, setListFilenames);
        LoadCardBack(pluginDirName);
        pluginCardpool_.SetPool(cardData);
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

void Plugin::LoadGameStructure(const QString &dirName) const
{
    QString fileName = QDir::cleanPath(dirName + "/ai/gamestructure.txt");
    try
    {
        QStringList dataLines = fileLoader_.FromFilename(fileName);
    }
    catch (iohelper::IoException& ex)
    {
        // TODO: this whole method is unfinished
    }
    // TODO: do something with data lines
}

// get file names of set lists (or carddata.txt if it has one list with all cards)
QStringList Plugin::GetSetListFilenames(const QString &pluginDirName) const
{
    QString fileName = QDir::cleanPath(pluginDirName + "/" + "setlist.txt");
    QStringList setNames;
    try
    {
        QStringList dataLines = fileLoader_.FromFilename(fileName);

        QString setLine = dataLines(0);
        // TODO: Where does this condition come from?
        if (setLine != "")
        {
            int setCount = setLine.toInt();
            for (int i = 1; i <= setCount; i++)
            {
                setNames << dataLines(i);
            }
        }
        else
        {
            setNames << QString("carddata.txt");
        }
    }
    catch (iohelper::IoException& ex)
    {
        setNames << QString("carddata.txt");
    }
    catch (std::exception& ex)
    {
        // TODO: this is a real error
    }

    return setNames;
}

// TODO: Implement handling of card back images
void Plugin::LoadCardBack(const QString &pluginDirName)
{

}

// Loads the card data from the set list files
QStringList Plugin::LoadCardData(const QString &pluginDirName, const QStringList &setListFilenames)
{
    QStringList overallList;
    QStringList dataLines;
    try
    {
    for (int i = 0; i < setListFilenames.size(); i++)
    {
        QString fileName
                = QDir::cleanPath(pluginDirName + "/" + QString("sets") + "/" + setListFilenames[i]);
        dataLines = fileLoader_.FromFilename(fileName);
        overallList << dataLines;
    }
    return overallList;
    }
    catch (iohelper::IoException& ex)
    {
        // TODO: re-throw or some plugin exception
    }
}

} // namespace plugin
