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

#include "gameloop.h"

namespace game {

Gameloop::Gameloop(Rulebook &currentRulebook) : currentRulebook_(currentRulebook)
{
}

void Gameloop::RunGame(std::shared_ptr<GameState> startState)
{
    // simplifications for prototype:
    // - support only turn structure where one player goes through all turn phases and then passes control to other player
    // - no reaction actions by the opponent yet
    // - move depth when checking value of a move only 1

    // required actions:
    // - execute best move
    // - break loop when game finish condition reached
    bool gameFinished = false;
    int currentPhase = 1;
    int activePlayer = 1;
    do
    {
        // get moves and rate them
//        std::vector<std::shared_ptr<Gamemove>> moveList = GetMoves(currentGamestate_);
//        std::multimap<int,std::shared_ptr<Gamemove>> ratedMoveList = RateMoves(moveList);
        // get best rated move
//        std::multimap<int,std::shared_ptr<Gamemove>>::iterator it=ratedMoveList.end();
//        std::shared_ptr<Gamemove> bestMovePtr = (*it).second;

//        Gamestate newGamestate = currentGamestate_.ExecuteMove(bestMove);
//        gameFinished = newGamestate.IsGameOver();
//        if (bestMove.type() == PASS)
//        {
//            currentPhase++;
//            if (currentPhase > numberOfPhases)
//            {
//                currentPhase = 1;
//                activePlayer++;
//                if (activePlayer > 2)
//                {
//                    activePlayer = 1;
//                }
//            }
//        }
    }
    while (!gameFinished);
}

void Gameloop::SetupGame(plugin::Deck deck1, plugin::Deck deck2)
{
    // TODO: create cards and put them on start positions
}

std::vector<std::shared_ptr<Gamemove>> Gameloop::GetMoves(const GameState &startState)
{
    // TODO: get all possible moves for the current gamestate
    std::vector<std::shared_ptr<Gamemove>> moveList;
    return moveList;
}

std::multimap<int, std::shared_ptr<Gamemove> >
    Gameloop::RateMoves(const std::vector<std::shared_ptr<Gamemove>> &availableMoves)
{
    std::multimap<int,std::shared_ptr<Gamemove>> ratedMoves;
    return ratedMoves;
}

} // namespace game
