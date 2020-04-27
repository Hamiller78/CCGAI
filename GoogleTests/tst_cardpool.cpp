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

#include "../Prototype/cardpool.h"

QStringList GetTestPoolData();

TEST(Cardpool, SetPoolAndMakeCardByIndex)
{
    plugin::Cardpool testPool();



}

QStringList GetTestPoolData()
{
    QStringList cardStrings;
    cardStrings << "Name\tSet\tImagefile\tType\tAttack\tDefense\tText";
    cardStrings << "Rookie\tBasic\tRookie.jpeg\tMinion\t1\t1\t";
    cardStrings << "Veteran\tBasic\tVeteran.jpeg\Minion\t2\t2\t";
    cardStrings << "Berserker\tBasic\tBerserker.jpeg\tMinion\t3\t1\tCharge";

    return cardStrings;
}
