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

#ifndef RULEBOOKMOCK_H
#define RULEBOOKMOCK_H

#include "board.h"
#include "cardpool.h"
#include "deck.h"
#include "rulebook.h"

#include <memory>

namespace game {

class RulebookMock : public Rulebook
{
public:
    RulebookMock();
    ~RulebookMock() override {}
    std::shared_ptr<GameState> SetupGame(const plugin::Deck& deck1, const plugin::Deck& deck2) const override;
private:
    void SpawnDeck(GameState &spawnState, const plugin::Deck &newDeck, const Position &spawnPosition) const;
};

} // namespace game

#endif // RULEBOOKMOCK_H
