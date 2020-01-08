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

#include <algorithm>
#include <stdexcept>
#include <map>
#include <memory>
#include <utility>

#include "igamepiece.h"
#include "objfactory.h"
#include "pile.h"

namespace game {

// Represents the state of a game board.
// Should be light-weight and allow quick creation of boards after applying moves
// objects of this class will be created a lot by AI calculation

using Position = std::pair<int, int>;

class Board
{
public:
    Board(const ObjFactory<Pile>& pileFactory) : pileFactory_(pileFactory){}
    Board(const Board& sourceBoard);
    ~Board();
    Board &operator=(const Board& otherBoard);
    void AddGamepiece(const std::shared_ptr<IGamepiece> newPiece, const Position& spawnPosition);
    std::shared_ptr<IGamepiece> GetTopPiece(const Position& pilePosition) const;
    void MovePile(const Position& startPosition, const Position& destinationPosition);
    void MoveTopPiece(const Position& startPosition, const Position& destinationPosition);
    void RemovePile(const Position& clearPosition);
private:
    const ObjFactory<Pile> &pileFactory_;
    std::map<Position, Pile*> pilesOnBoard_;
    void CopyBoardMembers(const Board& sourceBoard);
};

} // namespace game

#endif // BOARD_H
