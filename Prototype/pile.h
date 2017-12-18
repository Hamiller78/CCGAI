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

#ifndef PILE_H
#define PILE_H

#include "gamepiece.h"

#include <memory>
#include <stdexcept>
#include <utility>
#include <vector>

namespace game {

class Pile
{
public:
    Pile();
    void addOnTop(std::shared_ptr<Gamepiece> newPiece);
    void addPile(Pile *extraPile);
    void addToBottom(std::shared_ptr<Gamepiece> newPiece);
    std::vector<std::shared_ptr<Gamepiece>> getPieceVector();
    int getPilesize();
    std::shared_ptr<Gamepiece> getTopPiece();
    std::shared_ptr<Gamepiece> pickupTopPiece();
private:
    // vector containing the gamepieces in the pile
    // for efficiency the top piece is at the end of the vector
    std::vector<std::shared_ptr<Gamepiece>> pileElements_;
};

} // namespace game

#endif // PILE_H
