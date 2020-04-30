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

#ifndef MOCKGAMEPIECE_H
#define MOCKGAMEPIECE_H

#include "gmock/gmock.h"
#include "../Prototype/gamepiececard.h"

namespace mocks {

class MockGamepieceCard : public game::GamepieceCard
{
public:
    MockGamepieceCard() {}
    ~MockGamepieceCard() override {}

    MOCK_METHOD(std::shared_ptr<game::IGamepiece>, Clone, (), (override, const));

    MOCK_METHOD(void, SetOriginalCard, (const std::shared_ptr<GamepieceCard>&), (override));
    MOCK_METHOD(std::shared_ptr<GamepieceCard>, GetOriginalCard, (), (override, const));

    MOCK_METHOD(void, SetTraits, (const QString&, const QStringList&), (override));
    MOCK_METHOD(QString, GetTraitText, (const QString&), (override, const));
};

} // namespace mocks

#endif // MOCKGAMEPIECE_H
