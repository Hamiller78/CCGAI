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

#include "futuretree.h"

namespace ai {

void FutureTree::AddBranchesToNode(FutureTreeNode &currentNode)
{

}

void FutureTree::AddNodesToBranches(FutureTreeNode &currentNode)
{

}

/*
std::multimap<int, std::shared_ptr<game::Gamemove>>
  FutureTree::RateMoves(const std::shared_ptr<game::GameState> startState,
                                   const std::vector<std::shared_ptr<game::Gamemove> > &moveList
                                   ) const
{
    std::multimap<int, std::shared_ptr<game::Gamemove>> ratedMoves;
    for (auto const &currentMove : moveList)
    {
        game::GamemoveMock &curMove = dynamic_cast<game::GamemoveMock&>(*currentMove);
        std::shared_ptr<game::GameState> nextState = curMove.ApplyOnGamestate(startState);
        int moveRating = usedAnalyzer_.RateState(curMove.GetActivePlayer(), *nextState);
        ratedMoves.emplace(moveRating, currentMove);
    }
    return ratedMoves;
}
*/

} // namespace ai
