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

#include "playexpertmock.h"

namespace game {

std::multimap<int, std::shared_ptr<game::Gamemove>>
    game::PlayExpertMock::RateMoves(const game::GameState &currentState,
                                    const std::vector<std::shared_ptr<game::Gamemove> > &moveList) const
{
    // this throws a bad cast exception if the GameState is not a mock
    const GameStateMock &curStateMock = dynamic_cast<const GameStateMock&>(currentState);

    std::multimap<int, std::shared_ptr<game::Gamemove>> ratedMoves;
    for (auto &currentMove : moveList)
    {
        const GamemoveMock &curMoveMock = dynamic_cast<const GamemoveMock&>(*currentMove);
        const GameState nextState = curMoveMock.ApplyOnGamestate(curStateMock);
        int moveRating = RateState(nextState);
        ratedMoves.emplace(moveRating, currentMove);
    }
    return ratedMoves;
}

int PlayExpertMock::RateState(const GameState &rateState) const
{
    const GameStateMock &curStateMock = dynamic_cast<const GameStateMock&>(rateState);
    return curStateMock.GetStateNumber();
}

} // namespace game
