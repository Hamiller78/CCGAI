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

#ifndef CARDPOOL_H
#define CARDPOOL_H

#include <memory>
#include <vector>

#include <QString>
#include <QStringList>

#include "exceptionplugin.h"
#include "gamepiececard.h"
#include "icardpool.h"
#include "objfactory.h"

// Class to manage and spawn all possible cards.

namespace plugin {

class Cardpool : ICardpool
{

public:
    Cardpool(ObjFactory<game::GamepieceCard> cardFactory) : cardFactory_(cardFactory) {}

    virtual ~Cardpool(){}
    virtual std::shared_ptr<game::IGamepiece> MakeCard(int cardIndex) const override;
    virtual std::shared_ptr<game::IGamepiece> MakeCard(const QString& cardTitle) const override;
    virtual void SetPool(const QStringList& lackeyCardData);
private:
    void IdentifyKeyColumns();
    void MakeCardmasters(const QStringList& lackeyCardData);
    void ParseHeader(const QString& headerLine);

    ObjFactory<game::GamepieceCard> cardFactory_;

    int indexOfTitleColumn_{-1};
    int indexOfImageColumn_{-1};
    std::vector<std::shared_ptr<game::IGamepiece>> listOfCards_;
    QStringList namesOfColumns_;
};

} // namespace plugin

#endif // CARDPOOL_H
