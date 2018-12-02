/* Copyright (c) 2017,2018 Torben Kneesch

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

#include "card.h"
#include "cardpool.h"
#include "gamepiece.h"
#include "gamemove.h"

namespace game {

class GamemoveSpawnPiece : public Gamemove
{
public:
    GamemoveSpawnPiece(int activePlayer, int cardNumber, const Position& spawnPosition)
        : Gamemove(activePlayer), cardNumber_(cardNumber), spawnPosition_(spawnPosition){}
    std::shared_ptr<GameState> ApplyOnGamestate(const std::shared_ptr<GameState> oldState) override;
private:
    int cardNumber_;
    Position spawnPosition_;
};

} // namespace game

#endif // GAMEMOVESPAWNPIECE_H
