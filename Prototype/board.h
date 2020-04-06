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

#ifndef BOARD_H
#define BOARD_H

#include <QDebug>

#include <algorithm>
#include <map>
#include <memory>
#include <stdexcept>
#include <utility>

#include "iboard.h"
#include "igamepiece.h"
#include "objfactory.h"
#include "pile.h"

namespace game {

// Represents the state of a game board.
// Should be light-weight and allow quick creation of boards after applying moves
// objects of this class will be created a lot by AI calculation

class Board : IBoard
{
public:
    Board(const ObjFactory<Pile>& pileFactory) : pileFactory_(pileFactory){}
    virtual ~Board();

    Board(const Board& sourceBoard);
    Board(Board&& sourceBoard);
    Board& operator=(const Board& otherBoard);
    Board& operator=(Board&& otherBoard);
    std::unique_ptr<IBoard> Clone() const override;

    virtual void AddGamepiece(const std::shared_ptr<IGamepiece> newPiece, const Position& spawnPosition) override;
    virtual std::shared_ptr<IGamepiece> GetTopPiece(const Position& pilePosition) const override;
    virtual void MovePile(const Position& startPosition, const Position& destinationPosition) override;
    virtual void MoveTopPiece(const Position& startPosition, const Position& destinationPosition) override;
    virtual void RemovePile(const Position& clearPosition) override;
private:
    const ObjFactory<Pile> &pileFactory_;
    std::map<Position, Pile*> pilesOnBoard_;
    void CopyBoardMembers(const Board& sourceBoard);
};

} // namespace game

#endif // BOARD_H
