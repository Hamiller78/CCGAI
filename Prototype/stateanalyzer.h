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

#ifndef STATEANALYZER_H
#define STATEANALYZER_H

#include "gamestate.h"

// Base class for rating states
// Derived class may be wrappers for scripts etc...

namespace ai {

class StateAnalyzer
{
public:
    virtual ~StateAnalyzer() = 0;
    virtual int RateState(int actingPlayer, const game::GameState &rateState) const = 0;
};

} // namespace ai

#endif // STATEANALYZER_H
