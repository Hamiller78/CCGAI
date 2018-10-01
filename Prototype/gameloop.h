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

#ifndef GAMELOOP_H
#define GAMELOOP_H

#include <vector>

#include "deck.h"
#include "gamemove.h"
#include "gamestate.h"
#include "rulebook.h"

#include <memory>

// Class handling the gameloop.
// Requires setting a rulebook and an active cardpool.

namespace game {

class Gameloop
{
private:
//    GameState currentGamestate_;
    const Rulebook &currentRulebook_;
public:
    Gameloop(const Rulebook &currentRulebook);
    int RunGame(std::shared_ptr<GameState> startState);
private:
    std::vector<std::shared_ptr<Gamemove>> GetMoves(const GameState& startState);
    std::multimap<int,std::shared_ptr<Gamemove>>
        RateMoves(const std::vector<std::shared_ptr<Gamemove>> &availableMoves);
};

} // namespace game

#endif // GAMELOOP_H
