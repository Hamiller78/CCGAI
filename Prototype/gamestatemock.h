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

#ifndef GAMESTATEMOCK_H
#define GAMESTATEMOCK_H

#include "gamestate.h"

namespace game {

// Mock of gamestate class for tests
// Implemented as derived class from gamestate overriding the required methods
// Will only simulate a few GameStates indexed by the property stateNumber

class GameStateMock : public GameState
{
public:
    GameStateMock();
    GameStateMock(int stateNumber);
    int GetStateNumber() const {return stateNumber_;}
private:
    int stateNumber_{0};
};

} // namespace game

#endif // GAMESTATEMOCK_H
