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

#include "tst_googletest.h"

#include "MockCardpool.h"
#include "MockTextfileLoader.h"
#include "../Prototype/plugin.h"

QStringList GetSetlistTxtContent();
QStringList GetCarddataTxtContent();
QStringList GetExpectedSetCardpoolPar();

TEST(Plugin, LoadPlugin)
{
    const mocks::MockTextfileLoader mockLoader;
    mocks::MockCardpool mockPool;
    plugin::Plugin testPlugin(mockPool, mockLoader);

    EXPECT_CALL(mockLoader, CheckDirExists(QString("testdir"))).Times(1);
    EXPECT_CALL(mockLoader, FromFilename(QString("testdir/setlist.txt"))).Times(1).WillOnce(Return(GetSetlistTxtContent()));
    EXPECT_CALL(mockLoader, FromFilename(QString("testdir/sets/carddata.txt"))).Times(1).WillOnce(Return(GetCarddataTxtContent()));

    EXPECT_CALL(mockPool, CreatePool(GetExpectedSetCardpoolPar()));

    testPlugin.LoadPlugin("testdir");
}

QStringList GetSetlistTxtContent()
{
    QStringList fileContent;
    fileContent.append("1");
    fileContent.append("carddata.txt");

    return fileContent;
}

QStringList GetCarddataTxtContent()
{
    QStringList fileContent;
    fileContent.append("Name\tSet\tImagefile\tType\tAttack\tDefense\tText");
    fileContent.append("Rookie\tBasic\tRookie.jpeg\tMinion\t1\t1");
    fileContent.append("Veteran\tBasic\tVeteran.jpeg\tMinion\t2\t2");
    fileContent.append("Berserker\tBasic\tBerserker.jpeg\tMinion\t3\t1");

    return fileContent;
}

QStringList GetExpectedSetCardpoolPar()
{
    return GetCarddataTxtContent();
}
