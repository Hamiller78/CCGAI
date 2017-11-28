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

void Board::addGamepiece(std::shared_ptr<Gamepiece> newPiece, int x, int y)
{
    gamepiecesOnBoard[newPiece] = std::pair<int, int>(x, y);
}

std::shared_ptr<Gamepiece> Board::getTopPiece(int x, int y)
{

}

void Board::moveGamepiece(std::shared_ptr<Gamepiece> movePiece, int x, int y)
{
    gamepiecesOnBoard[movePiece] = std::pair<int, int>(x, y);
    // TO DO exception handling
}

void Board::removeGamepiece(std::shared_ptr<Gamepiece> removePiece)
{
    gamepiecesOnBoard.erase(removePiece);
    // TO DO exception handling
}

} // namespace game
