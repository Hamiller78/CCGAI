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

#include "deck.h"

namespace plugin {

Deck::Deck()
{

}

void Deck::LoadDecklistFromTxt(const QString &deckFileName)
{
    ClearDeck();
    QFile deckFile(deckFileName);
    if (deckFile.open(QIODevice::ReadWrite | QIODevice::Text))
    {
        QTextStream deckTextStream(&deckFile);
        ParseTxtTextstream(deckTextStream);
    }
}

void Deck::ParseTxtTextstream(QTextStream &fileContent)
{
    AddSidedeck("Draw Deck");
    QString deckLine = fileContent.readLine();
    while (!deckLine.isNull())
    {
        if (deckLine.right(1) == ":")
        {
            AddSidedeck(deckLine.left(deckLine.length() - 1));
        }
        else
        {
            AddCards(deckLine);
        }
        deckLine = fileContent.readLine();
    }
}

void Deck::AddCards(const QString &txtLine)
{
    QStringList lineContent = txtLine.split("\t");
    int cardCount = lineContent[0].toInt();
    for (int i = 1; i <= cardCount; i++)
    {
        deckLists_[deckNames_.size()-1].append(lineContent[1]);
    }
}

void Deck::AddSidedeck(const QString &sideDeckName)
{
    deckNames_.append(sideDeckName); //cut off ":"
    deckLists_.push_back(QStringList());
}

void Deck::ClearDeck()
{
    deckNames_.clear();
    deckLists_.clear();
}

} // namespace plugin
