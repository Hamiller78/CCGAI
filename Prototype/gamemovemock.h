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

#ifndef GAMEMOVEMOCK_H
#define GAMEMOVEMOCK_H

#include "gamemove.h"

namespace game {

// Mock class for gamemoves.
// Only uses an index number, which is good enough for the related mock classes.

using Position = std::pair<int, int>;

class GamemoveMock : public Gamemove
{
public:
    GamemoveMock(int moveNumber){moveNumber_ = moveNumber;}
    Board ApplyOnBoard(const Board& oldBoard) const override;
private:
    int moveNumber_{0};
};

} // namespace game

#endif // GAMEMOVEMOCK_H
