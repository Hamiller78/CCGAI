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

#include "../Prototype/deck.h"

QString GetTestFileContent1()
{
    QString fileContentString("10\tRookie\n");
    fileContentString.append("10\tVeteran\n");

    return fileContentString;
}

TEST(Deck, LoadDeckFromTextStream)
{
    plugin::Deck testDeck;
    QTextStream testFileContent;
    QString testFileString = GetTestFileContent1();
    testFileContent.setString(&testFileString, QIODevice::ReadOnly);

    testDeck.ParseTxtTextstream(testFileContent);

    QStringList deckNames = testDeck.GetDeckNames();
    ASSERT_EQ("Draw Deck", deckNames[0]);

    std::vector<QStringList> testDecks = testDeck.GetDeckLists();
    QStringList drawDeckList = testDecks[0];
    ASSERT_EQ(20, drawDeckList.size());
    for (int i = 0; i < 10; i++)
    {
        ASSERT_EQ("Rookie", drawDeckList[i]);
    }
    for (int i = 10; i < 20; i++)
    {
        ASSERT_EQ("Veteran", drawDeckList[i]);
    }
}
