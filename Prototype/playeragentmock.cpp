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

#include "playeragentmock.h"

namespace game {

std::shared_ptr<Gamemove>
    PlayerAgentMock::ChooseMove(const GameState &currentState,
                                const std::vector<std::shared_ptr<Gamemove> > &moveList) const
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
        return std::shared_ptr<Gamemove>(nullptr);
    }
}

std::multimap<int, std::shared_ptr<game::Gamemove>>
  game::PlayerAgentMock::RateMoves(const game::GameState &startState,
                                   const std::vector<std::shared_ptr<game::Gamemove> > &moveList
                                   ) const
{
    std::multimap<int, std::shared_ptr<game::Gamemove>> ratedMoves;
    for (auto const &currentMove : moveList)
    {
        const GamemoveMock &curMove = dynamic_cast<const GamemoveMock&>(*currentMove);
        const GameState nextState = curMove.ApplyOnGamestate(startState);
        int moveRating = RateState(curMove.GetActivePlayer(), nextState);
        ratedMoves.emplace(moveRating, currentMove);
    }
    return ratedMoves;
}

int PlayerAgentMock::RateState(int actingPlayer, const GameState &rateState) const
{
    if (actingPlayer == 2)
    {
        return -rateState.GetPoints(0);
    }
    else
    {
        return rateState.GetPoints(0);
    }
}

} // namespace game
