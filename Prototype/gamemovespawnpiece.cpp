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

#include "gamemovespawnpiece.h"

namespace game {

std::shared_ptr<plugin::ICardpool> GamemoveSpawnPiece::cardpool_;

GamemoveSpawnPiece::GamemoveSpawnPiece(int cardNumber, const Position &spawnPosition)
{
    cardNumber_ = cardNumber;
    spawnPosition_ = spawnPosition;
}

std::unique_ptr<IGameState> GamemoveSpawnPiece::ApplyOnGamestate(const IGameState &oldState) const
{
    std::unique_ptr<IGameState> newState = oldState.Clone();
    std::shared_ptr<IGamepiece> spawnPiece = cardpool_->MakeCard(cardNumber_);
    newState->GetBoard().AddGamepiece(spawnPiece, spawnPosition_);
    return newState;
}

} // namespace game
