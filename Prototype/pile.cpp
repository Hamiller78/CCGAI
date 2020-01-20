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

#include "pile.h"

namespace game {

Pile::Pile()
{

}

Pile::Pile(const Pile &sourcePile)
{
    pileElements_ = sourcePile.pileElements_;
}

Pile* Pile::CreateCopy() const
{
    Pile* newPile = new Pile;
    newPile->pileElements_ = pileElements_;
    return newPile;
}

void Pile::AddOnTop(const std::shared_ptr<IGamepiece> newPiece)
{
    pileElements_.push_back(newPiece);
}

void Pile::AddPile(Pile *extraPile)
{
    for (auto loopPiece : extraPile->GetPieceVector())
    {
        pileElements_.push_back(loopPiece);
    }
    extraPile->EmptyPile();
}

void Pile::AddToBottom(const std::shared_ptr<IGamepiece> newPiece)
{
    std::vector<std::shared_ptr<IGamepiece>>::iterator it;
    it = pileElements_.begin();
    pileElements_.insert(it, newPiece);
}

std::vector<std::shared_ptr<IGamepiece> > Pile::GetPieceVector()
{
    return pileElements_;
}

int Pile::GetPilesize() const
{
    return pileElements_.size();
}

std::shared_ptr<IGamepiece> Pile::GetTopPiece() const
{
    if (pileElements_.size() == 0)
    {
        throw std::logic_error("Attempted to access the top piece of an empty pile!");
    }
    return pileElements_.back();
}

std::shared_ptr<IGamepiece> Pile::PickupTopPiece()
{
    if (pileElements_.size() == 0)
    {
        throw std::logic_error("Attempted to access the top piece of an empty pile!");
    }
    std::shared_ptr<IGamepiece> topPiece = pileElements_.back();
    pileElements_.pop_back();
    return topPiece;
}

void Pile::EmptyPile()
{
    pileElements_.clear();
}

} // namespace game
