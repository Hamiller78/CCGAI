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

Board::~Board()
{
    for (auto pileIterator : pilesOnBoard)
    {
        delete pileIterator.second;
    }
}

void Board::addGamepiece(std::shared_ptr<Gamepiece> newPiece, Position spawnPosition)
{
    Pile* newPile = new Pile;
    pilesOnBoard[spawnPosition] = newPile;
}

void Board::movePile(Position startPosition, Position destinationPosition)
{
    auto pileIterator = pilesOnBoard.find(startPosition);
    if (pileIterator != pilesOnBoard.end())
    {
        Pile *movePile = pileIterator->second;
        pilesOnBoard.erase(pileIterator);
        pilesOnBoard[destinationPosition] = movePile;
    }
    else
    {
        throw std::logic_error("Attempted to move a pile from an empty board tile!");
    }
}

void Board::removePile(Position clearPosition)
{
    auto pileIterator = pilesOnBoard.find(clearPosition);
    if (pileIterator != pilesOnBoard.end())
    {
        delete pileIterator->second;
        pilesOnBoard.erase(pileIterator);
    }
    else
    {
        throw std::logic_error("Attempted to remove a pile from an empty board tile!");
    }
}

} // namespace game
