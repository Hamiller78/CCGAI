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

#ifndef GAMEMOVE_H
#define GAMEMOVE_H

#include "board.h"

namespace game {

// Base class for gamemoves. The possible moves are inheriting classes,
// whose function is to apply the move on a board.

using Position = std::pair<int, int>;

class Gamemove
{
public:
    Gamemove(){}
    virtual ~Gamemove(){}
    virtual Board applyOnBoard(const Board& oldBoard) const = 0;
};

} // namespace game

#endif // GAMEMOVE_H
