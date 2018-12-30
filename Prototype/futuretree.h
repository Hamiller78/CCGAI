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

#ifndef FUTURETREE_H
#define FUTURETREE_H

#include <memory>
#include <utility>
#include <vector>

#include "gamemove.h"
#include "stateanalyzer.h"

// Class to manage tree with possible future GameStates
// Optimization to calculate only promising GameStates should also be implemted here

namespace ai {

struct FutureTreeNode
{
    std:shared_ptr<game::GameState> state;
    int rating;
    std::vector<std::pair<std::shared_ptr<game::Gamemove>, std::shared_ptr<FutureTreeNode>>>
      branchMoves;
};


class FutureTree
{
public:
    FutureTree(const StateAnalyzer &usedAnalyzer) : usedAnalyzer_(usedAnalyzer){}
    std::shared_ptr<game::Gamemove>
      FindBestMove(const std::shared_ptr<game::GameState> startState, int player) const;
private:
    const StateAnalyzer &usedAnalyzer_;
    int turnDepth_{1};                // number of future turns are calculated
    int worthyRatingsInPercent_{10};  // parameter which fraction of the rating range is considered
                                      // good enough to calculate follow-up moves

    std::multimap<int, std::shared_ptr<game::Gamemove>>
      FutureTree::RateMoves(
                            const std::shared_ptr<game::GameState> startState,
                            const std::vector<std::shared_ptr<game::Gamemove> > &moveList
                            ) const;
};

} // namespace ai

#endif // FUTURETREE_H
