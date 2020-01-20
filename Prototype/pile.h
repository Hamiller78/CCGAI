/* Copyright (c) 2017-2020 Torben Kneesch

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

#include "igamepiece.h"

#include <memory>
#include <stdexcept>
#include <utility>
#include <vector>

namespace game {

class Pile
{
public:
    Pile();
    Pile(const Pile& sourcePile);
    virtual ~Pile() {}
    virtual void AddOnTop(const std::shared_ptr<IGamepiece> newPiece);
    virtual void AddPile(Pile* extraPile);
    void AddToBottom(const std::shared_ptr<IGamepiece> newPiece);
    virtual Pile* CreateCopy() const;
    virtual void EmptyPile();
    std::vector<std::shared_ptr<IGamepiece>> GetPieceVector();
    int GetPilesize() const;
    virtual std::shared_ptr<IGamepiece> GetTopPiece() const;
    virtual std::shared_ptr<IGamepiece> PickupTopPiece();
private:
    // vector containing the gamepieces in the pile
    // for efficiency the top piece is at the end of the vector
    std::vector<std::shared_ptr<IGamepiece>> pileElements_;
};

} // namespace game

#endif // PILE_H
