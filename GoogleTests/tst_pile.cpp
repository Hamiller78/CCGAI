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

#include "../Prototype/gamepiece.h"
#include "../Prototype/pile.h"

TEST(Pile, AddGamepieces)
{
    game::Pile testPile1;
    std::shared_ptr<game::Gamepiece> testPiecePtr1(new game::Gamepiece);
    std::shared_ptr<game::Gamepiece> testPiecePtr2(new game::Gamepiece);
    std::shared_ptr<game::Gamepiece> testPiecePtr3(new game::Gamepiece);

    testPile1.AddOnTop(testPiecePtr1);
    ASSERT_EQ(testPiecePtr1, testPile1.GetTopPiece());
    testPile1.AddOnTop(testPiecePtr2);
    ASSERT_EQ(testPiecePtr2, testPile1.GetTopPiece());
    testPile1.AddOnTop(testPiecePtr3);
    ASSERT_EQ(testPiecePtr3, testPile1.GetTopPiece());
    ASSERT_EQ(3, testPile1.GetPilesize());
}

TEST(Pile, AddPile)
{
    game::Pile testPile1;
    game::Pile testPile2;
    std::shared_ptr<game::Gamepiece> testPiecePtr1(new game::Gamepiece);
    std::shared_ptr<game::Gamepiece> testPiecePtr2(new game::Gamepiece);
    std::shared_ptr<game::Gamepiece> testPiecePtr3(new game::Gamepiece);
    std::shared_ptr<game::Gamepiece> testPiecePtr4(new game::Gamepiece);

    testPile1.AddOnTop(testPiecePtr1);
    testPile1.AddOnTop(testPiecePtr2);
    testPile2.AddOnTop(testPiecePtr3);
    testPile2.AddOnTop(testPiecePtr4);

    testPile2.AddPile(testPile1);
    ASSERT_EQ(4, testPile2.GetPilesize());
    ASSERT_EQ(testPiecePtr2, testPile2.GetTopPiece());
}

TEST(Pile, PickupTopPiece)
{
    game::Pile testPile1;
    std::shared_ptr<game::Gamepiece> testPiecePtr1(new game::Gamepiece);
    std::shared_ptr<game::Gamepiece> testPiecePtr2(new game::Gamepiece);
    std::shared_ptr<game::Gamepiece> testPiecePtr3(new game::Gamepiece);

    testPile1.AddOnTop(testPiecePtr1);
    testPile1.AddOnTop(testPiecePtr2);
    testPile1.AddOnTop(testPiecePtr3);
    std::shared_ptr<game::Gamepiece> checkPiece = testPile1.PickupTopPiece();
    ASSERT_EQ(2, testPile1.GetPilesize());
    ASSERT_EQ(testPiecePtr2, testPile1.GetTopPiece());
    ASSERT_EQ(testPiecePtr3, checkPiece);
}

TEST(Pile, AddToTopAndBottomAndGetVector)
{
    game::Pile testPile1;
    std::shared_ptr<game::Gamepiece> testPiecePtr1(new game::Gamepiece);
    std::shared_ptr<game::Gamepiece> testPiecePtr2(new game::Gamepiece);
    std::shared_ptr<game::Gamepiece> testPiecePtr3(new game::Gamepiece);
    std::shared_ptr<game::Gamepiece> testPiecePtr4(new game::Gamepiece);

    testPile1.AddOnTop(testPiecePtr1);
    testPile1.AddToBottom(testPiecePtr2);
    testPile1.AddOnTop(testPiecePtr3);
    testPile1.AddToBottom(testPiecePtr4);
    std::vector<std::shared_ptr<game::Gamepiece>> pieceList = testPile1.GetPieceVector();

    ASSERT_EQ(testPiecePtr4, pieceList[0]);
    ASSERT_EQ(testPiecePtr2, pieceList[1]);
    ASSERT_EQ(testPiecePtr1, pieceList[2]);
    ASSERT_EQ(testPiecePtr3, pieceList[3]);
}
