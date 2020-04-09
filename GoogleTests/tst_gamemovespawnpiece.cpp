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

#include "tst_googletest.h"

#include "MockBoard.h"
#include "MockCardpool.h"
#include "MockGamepiece.h"
#include "MockGamestate.h"
#include "../Prototype/gamemovespawnpiece.h"

TEST(GamemoveSpawnPiece, ApplyMoveToBoard)
{
    mocks::MockBoard mockBoard;
    std::shared_ptr<game::IGamepiece> mockCardPtr(new mocks::MockGamepiece);
    mocks::MockGameState mockGameState1;
    std::unique_ptr<mocks::MockGameState> mockGameState2(new mocks::MockGameState);
    mocks::MockGameState* mockGameStateRawPtr2 = mockGameState2.get();

    std::shared_ptr<mocks::MockCardpool> mockCardpoolPtr(new mocks::MockCardpool);
    game::GamemoveSpawnPiece::SetCardpool(mockCardpoolPtr);

    game::GamemoveSpawnPiece moveSpawnMove(7, game::Position(2,-1));

    EXPECT_CALL(mockGameState1, Clone()).Times(1).WillOnce(Return(ByMove(std::move(mockGameState2))));

    EXPECT_CALL(*mockCardpoolPtr, MakeCard(7)).Times(1).WillOnce(Return(mockCardPtr));
    EXPECT_CALL(*mockGameStateRawPtr2, GetBoard()).Times(1).WillOnce(ReturnRef(mockBoard));
    EXPECT_CALL(mockBoard, AddGamepiece(mockCardPtr, game::Position(2,-1))).Times(1);

    std::unique_ptr<game::IGameState> resultState = moveSpawnMove.ApplyOnGamestate(mockGameState1);

    ASSERT_EQ(mockGameStateRawPtr2, resultState.get());
}
