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

#ifndef GAMEPIECECARD_H
#define GAMEPIECECARD_H

#include <map>
#include <memory>

#include <QString>
#include <QStringList>

#include "igamepiece.h"

namespace game {

// Class to represent game cards.
// New instances of cards in the game should be created by calling the Clone() method of the
// respective instance of that card in the card pool.

class GamepieceCard : public IGamepiece
{
public:
    GamepieceCard() {}

    virtual std::shared_ptr<IGamepiece> Clone() const override;

    void SetOriginalCard(const std::shared_ptr<GamepieceCard>& originalCard) { originalCard_ = originalCard; }
    std::shared_ptr<GamepieceCard> GetOriginalCard() const { return originalCard_; }

    virtual void SetTraits(const QString& cardData, const QStringList& dataColumnTitles) override;
    virtual QString GetTraitText(const QString& trait) const override;

private:
    std::multimap<QString, QString> cardDataMap_;
    std::shared_ptr<GamepieceCard> originalCard_;
};

} // namespace game

#endif // GAMEPIECECARD_H
