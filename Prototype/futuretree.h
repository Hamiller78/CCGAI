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
#include "rulebook.h"
#include "stateanalyzer.h"

// Class to manage tree with possible future GameStates
// Optimization to calculate only promising GameStates should also be implemted here

namespace ai {

struct FutureTreeNode
{
    std::shared_ptr<game::GameState> state;
    std::shared_ptr<FutureTreeNode> parentNode;
    std::vector<std::tuple<std::shared_ptr<game::Gamemove>, int, std::shared_ptr<FutureTreeNode>>>
      branchMoves;
};


class FutureTree
{
public:
    FutureTree(const StateAnalyzer &usedAnalyzer, const game::Rulebook &usedRulebook)
        : usedAnalyzer_(usedAnalyzer), usedRulebook_(usedRulebook){}
    std::shared_ptr<game::Gamemove>
      FindBestMove(const std::shared_ptr<game::GameState> startState, int player) const;
    void SetDepth(int turnDepth){turnDepth_ = turnDepth;}
    void SetRatingsThreshold(int ratingsThreshold){ratingsThreshold_ = ratingsThreshold;}
private:
    const StateAnalyzer &usedAnalyzer_;
    const game::Rulebook &usedRulebook_;
    int treeSize_{0};
    int turnDepth_{1};                // number of future turns are calculated
    int ratingsThreshold_{10};        // threshold for fraction of the rating range to discard

    void AddBranchesToNode(FutureTreeNode &currentNode);
    void AddNodesToBranches(FutureTreeNode &currentNode);
};

} // namespace ai

#endif // FUTURETREE_H
