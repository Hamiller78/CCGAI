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

#include "MockCardFactory.h"
#include "MockGamepieceCard.h"

#include "../Prototype/cardpool.h"

QStringList GetTestPoolData();

QStringList GetColumnHeaders();
QString GetCardTraits(int CardIndex);
TEST(Cardpool, CreatePoolAndMakeCards)
{
    const mocks::MockCardFactory mockCardFactory;
    plugin::Cardpool testPool = plugin::Cardpool(mockCardFactory);

    mocks::MockGamepieceCard* mockCardPtr1 = new mocks::MockGamepieceCard;
    mocks::MockGamepieceCard* mockCardPtr2 = new mocks::MockGamepieceCard;

    EXPECT_CALL(mockCardFactory, CreatePtr())
        .Times(2)
        .WillOnce(Return(mockCardPtr1))
        .WillOnce(Return(mockCardPtr2));

    EXPECT_CALL(*mockCardPtr1, SetTraits(GetCardTraits(0), GetColumnHeaders())).Times(1);
    EXPECT_CALL(*mockCardPtr2, SetTraits(GetCardTraits(1), GetColumnHeaders())).Times(1);

    testPool.CreatePool(GetTestPoolData());

    std::shared_ptr<game::IGamepiece> mockPiecePtr4(new mocks::MockGamepieceCard);
    EXPECT_CALL(*mockCardPtr1, GetTraitText(QString("Name"))).Times(1).WillOnce(Return("Rookie"));
    EXPECT_CALL(*mockCardPtr2, GetTraitText(QString("Name"))).Times(1).WillOnce(Return("Veteran"));
    EXPECT_CALL(*mockCardPtr2, Clone()).Times(1).WillOnce(Return(mockPiecePtr4));
    std::shared_ptr<game::IGamepiece> clonedCardPtr = testPool.MakeCard("Veteran");
    ASSERT_EQ(mockPiecePtr4, clonedCardPtr);

    std::shared_ptr<game::IGamepiece> mockPiecePtr3(new mocks::MockGamepieceCard);
    EXPECT_CALL(*mockCardPtr1, Clone()).Times(1).WillOnce(Return(mockPiecePtr3));
    clonedCardPtr = testPool.MakeCard(0);
    ASSERT_EQ(mockPiecePtr3, clonedCardPtr);
}

QStringList GetTestPoolData()
{
    QStringList cardStrings;
    cardStrings.append(QString("Name\tSet\tImagefile\tType\tAttack\tDefense\tText"));
    cardStrings.append(QString("Rookie\tBasic\tRookie.jpeg\tMinion\t1\t1\t"));
    cardStrings.append(QString("Veteran\tBasic\tVeteran.jpeg\tMinion\t2\t2\t"));

    return cardStrings;
}

QStringList GetColumnHeaders()
{
    QStringList columnHeaders;
    columnHeaders << "Name";
    columnHeaders << "Set";
    columnHeaders << "Imagefile";
    columnHeaders << "Type";
    columnHeaders << "Attack";
    columnHeaders << "Defense";
    columnHeaders << "Text";

    return columnHeaders;
}

QString GetCardTraits(int cardIndex)
{
    QString cardTraits;
    if (cardIndex == 0)
    {
        cardTraits = QString("Rookie\tBasic\tRookie.jpeg\tMinion\t1\t1\t");
    }
    else if (cardIndex == 1)
    {
        cardTraits = QString("Veteran\tBasic\tVeteran.jpeg\tMinion\t2\t2\t");
    }

    return cardTraits;
}