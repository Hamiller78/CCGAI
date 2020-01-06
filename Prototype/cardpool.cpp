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

#include "cardpool.h"

namespace plugin {

Cardpool &Cardpool::GetInstance()
{
    static Cardpool instance;
    return instance;
}

std::shared_ptr<game::GamepieceCard> Cardpool::MakeCard(int cardIndex)
{
    std::shared_ptr<game::GamepieceCard> newCard(new game::GamepieceCard(listOfCards_[cardIndex]));
    return newCard;
}

std::shared_ptr<game::GamepieceCard> Cardpool::MakeCard(QString cardTitle)
{
    uint cardIndex;
    for (cardIndex = 0; cardIndex < listOfCards_.size(); cardIndex++)
    {
        QString loopCardName = listOfCards_[cardIndex].get()->GetTraitText("Name");
        if (cardTitle == loopCardName)
        {
            break;
        }
    }
    if (cardIndex >= listOfCards_.size())
    {
        throw ExceptionPlugin("Requested card to make not found in list: "
                              + cardTitle.toStdString());
    }
    return MakeCard(cardIndex);
}

void Cardpool::SetPool(const QStringList &lackeyCardData)
{
    if (lackeyCardData.size() < 2)
    {
        throw ExceptionPlugin("No card data found!");
    }
    ParseHeader(lackeyCardData[0]);
    MakeCardmasters(lackeyCardData);
    IdentifyKeyColumns();
}

void Cardpool::IdentifyKeyColumns()
{
    indexOfImage_ = namesOfColumns_.indexOf(QRegExp("Name", Qt::CaseInsensitive));
    indexOfTitle_ = namesOfColumns_.indexOf(QRegExp("ImageFile", Qt::CaseInsensitive));
    if (indexOfImage_ == -1)
    {
        throw ExceptionPlugin("ImageFile column in carddata.txt not found!");
    }
    if (indexOfTitle_ == -1)
    {
        throw ExceptionPlugin("Name column in carddata.txt not found!");
    }
}

void Cardpool::MakeCardmasters(const QStringList &lackeyCardData)
{
    listOfCards_.clear();
    for (int i = 1; i < lackeyCardData.size(); i++)
    {
        std::shared_ptr<Cardmaster> newCardmaster(new Cardmaster(lackeyCardData[i], namesOfColumns_));
        listOfCards_.push_back(newCardmaster);
    }
}

void Cardpool::ParseHeader(const QString &headerLine)
{
    namesOfColumns_.clear();
    namesOfColumns_ = headerLine.split("\t");
}

} // namespace plugin
