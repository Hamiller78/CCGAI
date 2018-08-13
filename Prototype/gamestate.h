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
#include "gamemove.h"

#include <memory>

namespace game {

// Contains the complete description of the game
// including board and later arrow/targets and external counters

class GameState
{
public:
    GameState();
    void SetBoard(std::shared_ptr<Board> newBoard){containedBoard_ = newBoard;}
//    GameState ExecuteMove(Gamemove execMove);
    bool IsGameOver();
private:
    std::shared_ptr<Board> containedBoard_{nullptr};
};

} // namespace game

#endif // GAMESTATE_H
