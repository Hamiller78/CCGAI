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

#ifndef PLAYERAGENTAI_H
#define PLAYERAGENTAI_H

#include "futuretree.h"
#include "gamemove.h"
#include "gamemovemock.h"
#include "gamestate.h"
#include "playeragent.h"
#include "stateanalyzer.h"

#include <map>
#include <memory>

// Class for AI
// Main task is to select the best move out of a list of possible moves

namespace ai {

class PlayerAgentAi : public PlayerAgent
{
public:
    PlayerAgentAi(const int playerNumber, const StateAnalyzer &usedAnalyzer);
    ~PlayerAgentAi() override;

    int GetTurnDepth(){return turnDepth_;}
    void SetTurnDepth(const int turnDepth){turnDepth_ = turnDepth;}

    virtual std::shared_ptr<game::Gamemove>
        ChooseMove(const std::shared_ptr<game::GameState> currentState,
                   const std::vector<std::shared_ptr<game::Gamemove>> &moveList) const override;
protected:
    std::multimap<int,std::shared_ptr<game::Gamemove>>
        RateMoves(const std::shared_ptr<game::GameState> startState,
                  const std::vector<std::shared_ptr<game::Gamemove>> &moveList
                  ) const;
private:
    int turnDepth_{1};
    int worthyRatingsInPercent_{10};  // parameter which fraction of the rating range is considered
                                      // good enough to calculate follow-up moves
    FutureTree *FutureTree_;
};

} // namespace ai

#endif // PLAYERAGENTAI_H
