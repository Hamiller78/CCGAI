/* Copyright (c) 2018 Torben Kneesch

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

#include "rulebookmock.h"

namespace game {

RulebookMock::RulebookMock()
{

}

std::shared_ptr<GameState> RulebookMock::SetupGame(const plugin::Deck &deck1,
                                                   const plugin::Deck &deck2) const
{
    std::shared_ptr<GameState> newState(new GameState());
    SpawnDeck(*newState, deck1, Position(1, -1));
    SpawnDeck(*newState, deck2, Position(-1, 1));
    return newState;
}

void RulebookMock::SpawnDeck(GameState &spawnState, const plugin::Deck &newDeck,
                             const Position &spawnPosition) const
{
    std::vector<QStringList> deckLists = newDeck.GetDeckLists();
    for (int i = 0; i < deckLists[0].size(); i++)
    {
        std::shared_ptr<Card> newCardPtr
                = plugin::Cardpool::GetInstance().MakeCard(deckLists[0].at(i));
        spawnState.AddGamepiece(newCardPtr, spawnPosition);
    }
}

} // namespace game
