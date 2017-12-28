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

#include "cardpool.h"

namespace plugin {

Cardpool::Cardpool()
{

}

void Cardpool::setPool(const QStringList &lackeyCardData)
{
    if (lackeyCardData.size() >= 2)
    {
        throw ExceptionPlugin("No card data found!");
    }
    parseHeader(lackeyCardData[0]);
    makeCardmasters(lackeyCardData);
}

void Cardpool::parseHeader(const QString &headerLine)
{
    namesOfColumns_.clear();
    namesOfColumns_ = headerLine.split("\t");
}

void Cardpool::makeCardmasters(const QStringList &lackeyCardData)
{
    listOfCards_.clear();
    for (int i = 1; i < lackeyCardData.size(); i++)
    {
        Cardmaster *newCardmaster = new Cardmaster(lackeyCardData[i], namesOfColumns_);
        listOfCards_.push_back(newCardmaster);
    }
}

} // namespace plugin