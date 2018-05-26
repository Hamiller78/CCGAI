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

#include "gamemove.h"
#include "gamestate.h"

namespace game {

class Gameloop
{
private:
    GameState currentGamestate_;
public:
    Gameloop();
    void RunGame();
    void SetupGame();
private:
    std::vector<std::shared_ptr<Gamemove>> GetMoves(const GameState& startState);
    std::map<std::shared_ptr<Gamemove>,int> RateMoves(const std::vector<std::shared_ptr<Gamemove>> &availableMoves);
};

} // namespace game

#endif // GAMELOOP_H
