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

#include "gamepiececard.h"

namespace game {

    std::shared_ptr<IGamepiece> GamepieceCard::Clone() const
    {
        std::shared_ptr<GamepieceCard> clonedCardPtr(new GamepieceCard);

        clonedCardPtr->cardDataMap_ = cardDataMap_;

        return clonedCardPtr;
    }

    void GamepieceCard::SetTraits(const QString& cardData, const QStringList& dataColumnTitles)
    {
        QStringList cardTraits;
        cardTraits = cardData.split("\t");
        for (int i = 0; i < std::min(cardTraits.size(), dataColumnTitles.size()); i++)
        {
            if (cardTraits[i] != "")
            {
                cardDataMap_.insert(std::pair<QString, QString>(dataColumnTitles[i], cardTraits[i]));
            }
        }
    }

    QString GamepieceCard::GetTraitText(const QString& trait) const
    {
        auto it = cardDataMap_.find(trait);
        if (it != cardDataMap_.end())
        {
            return it->second;
        }
        else
        {
            return QString("");
        }
    }

} // namespace game