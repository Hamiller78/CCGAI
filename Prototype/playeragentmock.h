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

#ifndef PLAYERAGENTMOCK_H
#define PLAYERAGENTMOCK_H

#include "gamemove.h"
#include "gamemovemock.h"
#include "gamestatemock.h"
#include "playeragent.h"

#include <map>
#include <memory>

// Mock for PlayExpert class
// Will only rate mock moves and states according to their index number

namespace game {

class PlayerAgentMock : public PlayerAgent
{
public:
    PlayerAgentMock(){}
    ~PlayerAgentMock() override {}
    virtual std::shared_ptr<Gamemove>
        ChooseMove(const GameState &currentState,
                   const std::vector<std::shared_ptr<Gamemove>> &moveList) const override;
private:
    std::multimap<int,std::shared_ptr<Gamemove>>
      RateMoves(const GameState &currentState,
                const std::vector<std::shared_ptr<Gamemove>> &moveList) const;
    int RateState(const GameState &rateState) const;
};

} // namespace game

#endif // PLAYERAGENTMOCK_H
