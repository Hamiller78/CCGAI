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
    game::PlayerAgentMock::RateMoves
        (const game::GameState &currentState,
         const std::vector<std::shared_ptr<game::Gamemove> > &moveList) const
{
    // this throws a bad cast exception if the GameState is not a mock
    const GameState &curState = dynamic_cast<const GameState&>(currentState);

    std::multimap<int, std::shared_ptr<game::Gamemove>> ratedMoves;
    for (auto const &currentMove : moveList)
    {
//        const GamemoveMock &curMoveMock = dynamic_cast<const GamemoveMock&>(*currentMove);
//        const GameStateMock nextStateMock
//                = curMoveMock.ApplyOnGamestateMock(curStateMock);
//        int moveRating = RateState(nextStateMock);
//        ratedMoves.emplace(moveRating, currentMove);
    }
    return ratedMoves;
}

int PlayerAgentMock::RateState(const GameState &rateState) const
{
    const GameState &curState = dynamic_cast<const GameState&>(rateState);
    return curState.GetPoints(0);
}

} // namespace game
