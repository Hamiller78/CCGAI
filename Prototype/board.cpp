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

#include "board.h"

namespace game {

Board::Board()
{

}

Board::Board(const Board &sourceBoard)
{
    for (auto loopPile : sourceBoard.pilesOnBoard_)
    {
        Pile* pileCopy = new Pile(*loopPile.second);
        pilesOnBoard_[loopPile.first] = pileCopy;
    }
}

Board::~Board()
{
    for (auto pileIterator : pilesOnBoard_)
    {
        delete pileIterator.second;
    }
}

void Board::AddGamepiece(const std::shared_ptr<Gamepiece> newPiece, const Position& spawnPosition)
{
    Pile* addPile = pilesOnBoard_[spawnPosition];
    if (addPile == nullptr)
    {
        addPile = new Pile;
        pilesOnBoard_[spawnPosition] = addPile;
    }
    addPile->AddOnTop(newPiece);
}

std::shared_ptr<Gamepiece> Board::GetTopPiece(const Position &pilePosition) const
{
    Pile* readPile = pilesOnBoard_.at(pilePosition);
    return readPile->GetTopPiece();
}

void Board::MovePile(const Position &startPosition, const Position &destinationPosition)
{
    auto pileIterator = pilesOnBoard_.find(startPosition);
    if (pileIterator == pilesOnBoard_.end())
    {
        throw std::logic_error("Attempted to move a pile from an empty board tile!");
    }
    Pile *movePile = pileIterator->second;
    pilesOnBoard_.erase(pileIterator);

    Pile *targetPile = pilesOnBoard_[destinationPosition];
    if (targetPile == nullptr)
    {
        pilesOnBoard_[destinationPosition] = movePile;
    }
    else
    {
        targetPile->AddPile(*movePile);
    }
}

void Board::MoveTopPiece(const Position &startPosition, const Position &destinationPosition)
{
    Pile* readPile = pilesOnBoard_.at(startPosition);
    std::shared_ptr<Gamepiece> pickedPiece = readPile->PickupTopPiece();
    AddGamepiece(pickedPiece, destinationPosition);
    if (readPile->GetPilesize() == 0)
    {
        pilesOnBoard_[startPosition] = nullptr;
        delete readPile;
    }
}

void Board::RemovePile(const Position &clearPosition)
{
    auto pileIterator = pilesOnBoard_.find(clearPosition);
    if (pileIterator != pilesOnBoard_.end())
    {
        delete pileIterator->second;
        pilesOnBoard_.erase(pileIterator);
    }
    else
    {
        throw std::logic_error("Attempted to remove a pile from an empty board tile!");
    }
}

} // namespace game
