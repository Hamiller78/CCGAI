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

Gameloop::Gameloop()
{

}

void Gameloop::RunGame()
{
    // simplifications for prototype:
    // - support only turn structure where one player goes through all turn phases and then passes control to other player
    // - no reaction actions by the opponent yet
    // - move depth when checking value of a move only 1

    // required actions:
    // - get possible moves for current gamestate
    // - get estimated value for each move
    // - execute best move
    // - break loop when game finish condition reached
    bool gameFinished = false;
    int currentPhase = 1;
    int activePlayer = 1;
/*    do
    {
        std::vector<Gamemove> moveList = GetMoves(currentGamestate_);
        std:vector<Gamemove> ratedMoveList = RateMoves(moveList);
        ratedMoveList.sort();
        Gamemove bestMove = ratedMoveList.top();
        Gamestate newGamestate = currentGamestate_.ExecuteMove(bestMove);
        gameFinished = newGamestate.IsGameOver();
        if (bestMove.type() == PASS)
        {
            currentPhase++;
            if (currentPhase > numberOfPhases)
            {
                currentPhase = 1;
                activePlayer++;
                if (activePlayer > 2)
                {
                    activePlayer = 1;
                }
            }
        }
    }
    while (!gameFinished) */
}

void Gameloop::SetupGame()
{
    // create cards and put them on start positions
}

} // namespace game
