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

#ifndef GAMEMOVESPAWNPIECE_H
#define GAMEMOVESPAWNPIECE_H

#include <utility>

#include "gamepiececard.h"
#include "cardpool.h"
#include "igamepiece.h"
#include "gamemove.h"

namespace game {

class GamemoveSpawnPiece : public Gamemove
{
private:
    int cardNumber_;
    Position spawnPosition_;
    static std::shared_ptr<plugin::Cardpool> cardpool_;
public:
    GamemoveSpawnPiece(int cardNumber, const Position& spawnPosition);
    std::unique_ptr<IGameState> ApplyOnGamestate(const IGameState& oldState) const override;
    static void SetCardpool(std::shared_ptr<plugin::Cardpool> cardpool) {cardpool_ = cardpool;}
};

} // namespace game

#endif // GAMEMOVESPAWNPIECE_H
