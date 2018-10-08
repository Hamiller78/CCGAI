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

    std::shared_ptr<GameState> newState(new GameStateMock(1));
    return newState;
}

std::vector<std::shared_ptr<Gamemove>> RulebookMock::GetPossibleMoves(const GameState &currentState) const
{
    std::vector<std::shared_ptr<Gamemove>> returnMoves;
    std::shared_ptr<Gamemove> tempMock;

    // the rulebook mock can only handle GameStateMocks
    try
    {
        const GameStateMock&currentStateMock = dynamic_cast<const GameStateMock&>(currentState);

        // Return fixed GamemoveMocks depending on state number
        switch(currentStateMock.GetStateNumber())
        {
        case 1:
            tempMock = std::shared_ptr<GamemoveMock>(new GamemoveMock(1));
            returnMoves.push_back(tempMock);
            tempMock = std::shared_ptr<GamemoveMock>(new GamemoveMock(2));
            returnMoves.push_back(tempMock);
            break;
        case 2:
            tempMock = std::shared_ptr<GamemoveMock>(new GamemoveMock(1));
            returnMoves.push_back(tempMock);
            tempMock = std::shared_ptr<GamemoveMock>(new GamemoveMock(2));
            returnMoves.push_back(tempMock);
            break;
        case 3:
            tempMock = std::shared_ptr<GamemoveMock>(new GamemoveMock(1));
            returnMoves.push_back(tempMock);
            tempMock = std::shared_ptr<GamemoveMock>(new GamemoveMock(2));
            returnMoves.push_back(tempMock);
            tempMock = std::shared_ptr<GamemoveMock>(new GamemoveMock(3));
            returnMoves.push_back(tempMock);
            break;
        case 4:
            tempMock = std::shared_ptr<GamemoveMock>(new GamemoveMock(1));
            returnMoves.push_back(tempMock);
            break;
        case 5:
            tempMock = std::shared_ptr<GamemoveMock>(new GamemoveMock(1));
            returnMoves.push_back(tempMock);
            tempMock = std::shared_ptr<GamemoveMock>(new GamemoveMock(2));
            returnMoves.push_back(tempMock);
            break;
        case 6:
            tempMock = std::shared_ptr<GamemoveMock>(new GamemoveMock(1));
            returnMoves.push_back(tempMock);
            break;
        default:
            throw (std::logic_error("RulebookMock called with illegal GamestateMock."));
        }
    }
    catch (std::bad_cast)
    {
        throw(std::logic_error("RulebookMock was called with a GameState that is not a mock!"));
    }

    return returnMoves;
}

} // namespace game
