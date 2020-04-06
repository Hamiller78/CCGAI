/* Copyright (c) 2018-2020 Torben Kneesch

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

#include "iboard.h"

#include <memory>
#include <vector>

namespace game {

// Contains the complete description of the game
// including board and later arrow/targets and external counters

class GameState
{
private:
    std::unique_ptr<IBoard> board_;
    static unsigned int numberOfPointCounters_;
    static unsigned int countInstances_;
    std::vector<int> *pointCounters_{nullptr};
public:
    GameState(std::unique_ptr<IBoard>&& newBoard);
    ~GameState();
    GameState(const GameState& sourceState);
    GameState(GameState&& sourceState);
    GameState &operator=(const GameState& otherState);
    GameState &operator=(GameState&& otherState);

    std::unique_ptr<IBoard>& GetBoard() {return board_;}

    static unsigned int GetNumberOfPointCounters(){return numberOfPointCounters_;}
    // only allowed while no objects are instantiated
    // will throw a runtime exception if tried otherwise
    static void SetNumberOfPointCounters(unsigned int newNumber);

    void AlterPoints(unsigned int pointIndex, int relativeValue);
    int GetPoints(unsigned int pointIndex) const;
    void SetPoints(unsigned int pointIndex, int absoluteValue);
private:
    void CopyPointCounters(const GameState& sourceState);
};

} // namespace game

#endif // GAMESTATE_H
