/* Copyright (c) 2020 Torben Kneesch

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

#ifndef IBOARD_H
#define IBOARD_H

#include "igamepiece.h"

#include <memory>
#include <utility>

namespace game {

using Position = std::pair<int, int>;

class IBoard
{
public:
    virtual ~IBoard() {}

//    virtual IBoard(const IBoard& sourceBoard);
//    virtual IBoard(IBoard&& sourceBoard);
    virtual std::unique_ptr<IBoard> Clone() const = 0;

    virtual void AddGamepiece(const std::shared_ptr<IGamepiece> newPiece, const Position& spawnPosition) = 0;
    virtual std::shared_ptr<IGamepiece> GetTopPiece(const Position& pilePosition) const = 0;
    virtual void MovePile(const Position& startPosition, const Position& destinationPosition) = 0;
    virtual void MoveTopPiece(const Position& startPosition, const Position& destinationPosition) = 0;
    virtual void RemovePile(const Position& clearPosition) = 0;
};

} // namespace game

#endif // IBOARD_H
