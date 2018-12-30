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

#include "playeragentai.h"

namespace ai {

PlayerAgentAi::PlayerAgentAi(const int playerNumber, const StateAnalyzer &usedAnalyzer)
    : PlayerAgent(playerNumber)
{
    FutureTree_ = new FutureTree(usedAnalyzer);
}

PlayerAgentAi::~PlayerAgentAi()
{
    delete FutureTree_;
}

std::shared_ptr<game::Gamemove>
    PlayerAgentAi::ChooseMove(const std::shared_ptr<game::GameState> currentState,
                                const std::vector<std::shared_ptr<game::Gamemove>> &moveList) const
{
    // look for best move iteratively
    // loop over GameDepth
      // get list of resulting GameStates
      // get list of legal moves to each GameState
    //??? What about opponent's moves
      // rate from opponent's view

    const std::multimap<int, std::shared_ptr<game::Gamemove>> ratedMoveList
            = RateMoves(currentState, moveList);
    if (ratedMoveList.size() > 0)
    {
        auto topMoveIter = ratedMoveList.end();
        topMoveIter--;
        return topMoveIter->second;
    }
    else
    {
        return std::shared_ptr<game::Gamemove>(nullptr);
    }
}

} // namespace ai
