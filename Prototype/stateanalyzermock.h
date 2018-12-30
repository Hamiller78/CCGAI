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

#ifndef STATEANALYZERMOCK_H
#define STATEANALYZERMOCK_H

#include "stateanalyzer.h"

// Mock class to rate GameStates
// In this implementation of the StateAnalyzer simply the point value of a state is used to rate it

namespace ai {

class StateAnalyzerMock : public StateAnalyzer
{
public:
    StateAnalyzerMock();
    virtual int RateState(int actingPlayer, const game::GameState &rateState) const override;
};

} // namespace ai

#endif // STATEANALYZERMOCK_H
