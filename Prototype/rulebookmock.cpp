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
    // decks are not used in mock
    Q_UNUSED(deck1);
    Q_UNUSED(deck2);

    std::shared_ptr<GameState> newState(new GameState());
    return newState;
}

std::vector<std::shared_ptr<Gamemove>> RulebookMock::GetPossibleMoves(const GameState &currentState) const
{
    std::vector<std::shared_ptr<Gamemove>> returnMoves;
    std::shared_ptr<Gamemove> tempMock;

    // the rulebook mock can only handle GameStateMocks
    try
    {
        const GameState &currentState = dynamic_cast<const GameState&>(currentState);

        // Return fixed GamemoveMocks
        tempMock = std::shared_ptr<GamemoveMock>(new GamemoveMock(-1));
        returnMoves.push_back(tempMock);
        tempMock = std::shared_ptr<GamemoveMock>(new GamemoveMock(3));
        returnMoves.push_back(tempMock);
    }
    catch (std::bad_cast)
    {
        throw(std::logic_error("RulebookMock was called with a GameState that is not a mock!"));
    }

    return returnMoves;
}

int RulebookMock::HasSomeoneWon(const GameState &currentState) const
{
    const GameState &currentStateMock = dynamic_cast<const GameState&>(currentState);
    if (currentState.GetPoints(0) == 99)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

} // namespace game
