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

    // Return fixed GamemoveMocks only depending whether Gametate is even or odd
    if (currentState.GetPoints(0) % 2 == 0)
    {
        // possible moves from even states
        tempMock = std::shared_ptr<GamemoveMock>(new GamemoveMock(1, 6));
        returnMoves.push_back(tempMock);
        tempMock = std::shared_ptr<GamemoveMock>(new GamemoveMock(2, 1));
        returnMoves.push_back(tempMock);
        tempMock = std::shared_ptr<GamemoveMock>(new GamemoveMock(2, -2));
        returnMoves.push_back(tempMock);
    }
    else
    {
        // possible moves from odd state
        tempMock = std::shared_ptr<GamemoveMock>(new GamemoveMock(2, -4));
        returnMoves.push_back(tempMock);
        tempMock = std::shared_ptr<GamemoveMock>(new GamemoveMock(1, 2));
        returnMoves.push_back(tempMock);
    }
    return returnMoves;
}

int RulebookMock::HasSomeoneWon(const GameState &currentState) const
{
    if (currentState.GetPoints(0) >= 20)
    {
        return 1;
    }
    else if (currentState.GetPoints(0) <= -20)
    {
        return 2;
    }
    else
    {
        return 0;
    }
}

} // namespace game
