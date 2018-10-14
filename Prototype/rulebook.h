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

#ifndef RULEBOOK_H
#define RULEBOOK_H

#include "board.h"
#include "deck.h"
#include "gamemove.h"
#include "gamestate.h"

#include <memory>

// Interface class to manage specific game rules.
// Implementations should be in derived classes.

namespace game {

using Position = std::pair<int, int>;

class Rulebook
{
public:
    Rulebook(){}
    virtual ~Rulebook(){}
    virtual std::shared_ptr<GameState> SetupGame(const plugin::Deck& deck1, const plugin::Deck& deck2) const = 0;
    virtual std::vector<std::shared_ptr<Gamemove>> GetPossibleMoves(const GameState& currentState) const = 0;
    virtual int HasSomeoneWon(const GameState& currentState) const = 0;
};

} // namespace game

#endif // RULEBOOK_H
