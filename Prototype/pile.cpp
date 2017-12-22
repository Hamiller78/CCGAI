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

#include "pile.h"

namespace game {

Pile::Pile()
{

}

Pile::Pile(const Pile &sourcePile)
{
    pileElements_ = sourcePile.pileElements_;
}

void Pile::addOnTop(std::shared_ptr<Gamepiece> newPiece)
{
    pileElements_.push_back(newPiece);
}

void Pile::addPile(Pile *extraPile)
{
    for (auto loopPiece : extraPile->getPieceVector())
    {
        pileElements_.push_back(loopPiece);
    }
    extraPile->emptyPile();
}

void Pile::addToBottom(std::shared_ptr<Gamepiece> newPiece)
{
    std::vector<std::shared_ptr<Gamepiece>>::iterator it;
    it = pileElements_.begin();
    pileElements_.insert(it, newPiece);
}

std::vector<std::shared_ptr<Gamepiece> > Pile::getPieceVector()
{
    return pileElements_;
}

int Pile::getPilesize()
{
    return pileElements_.size();
}

std::shared_ptr<Gamepiece> Pile::getTopPiece()
{
    if (pileElements_.size() == 0)
    {
        throw std::logic_error("Attempted to access the top piece of an empty pile!");
    }
    return pileElements_.back();
}

std::shared_ptr<Gamepiece> Pile::pickupTopPiece()
{
    if (pileElements_.size() == 0)
    {
        throw std::logic_error("Attempted to access the top piece of an empty pile!");
    }
    std::shared_ptr<Gamepiece> topPiece = pileElements_.back();
    pileElements_.pop_back();
    return topPiece;
}

void Pile::emptyPile()
{
    pileElements_.clear();
}

} // namespace game
