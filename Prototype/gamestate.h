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

#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "board.h"

#include <memory>

namespace game {

// Contains the complete description of the game
// including board and later arrow/targets and external counters

class GameState : public Board
{
private:
    static int numberOfPointCounters_;
public:
    GameState();
    GameState(const GameState& sourceState);
    virtual ~GameState(){}
    GameState &operator=(const GameState& otherState);

    static int GetNumberOfPointCounters(){return numberOfPointCounters_;}
    static void SetNumberOfPointCounters(int newNumber){numberOfPointCounters_ = newNumber;}

    void AlterPoints(int pointIndex, int relativeValue);
    int GetPoints(int pointIndex);
    void SetPoints(int pointIndex, int absoluteValue);

private:

};

} // namespace game

#endif // GAMESTATE_H
