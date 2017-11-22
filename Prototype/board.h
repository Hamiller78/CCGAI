/* Copyright (c) 2017 Torben Kneesch

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

#ifndef BOARD_H
#define BOARD_H

#include "memory"
#include "tuple"
#include "vector"

#include "gamemove.h"
#include "gamepiece.h"

namespace game {

class Board
{
public:
    Board();
    void addGamepiece(std::shared_ptr<Gamepiece> newPiece, int x, int y);
    void moveGamepiece(std::shared_ptr<Gamepiece> movePiece, int x, int y);
    void removeGamepiece(std::shared_ptr<Gamepiece> removePiece);
    std::shared_ptr<Gamepiece> getTopPiece(int x, int y);
};

} // namespace game

#endif // BOARD_H
