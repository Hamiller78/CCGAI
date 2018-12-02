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

#ifndef PLAYERAGENT_H
#define PLAYERAGENT_H

#include "gamemove.h"
#include "gamestate.h"

#include <memory>
#include <vector>

// Base class to manage possible players like AI, GUI interface for human player,
//   network connection...
// Implementations should be in derived classes.

namespace game {

class PlayerAgent
{
protected:
    const int playerNumber_{1};
public:
    PlayerAgent(const int playerNumber) : playerNumber_(playerNumber){}
    virtual ~PlayerAgent(){}
    virtual std::shared_ptr<Gamemove>
        ChooseMove(const std::shared_ptr<GameState> currentState,
                   const std::vector<std::shared_ptr<Gamemove>> &moveList) const = 0;
};

} // namespace game

#endif // PLAYERAGENT_H
