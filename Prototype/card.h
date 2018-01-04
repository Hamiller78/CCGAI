/* Copyright (c) 2017 Torben Kneesch

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

#ifndef CARD_H
#define CARD_H

#include <memory>

#include "cardmaster.h"
#include "gamepiece.h"

namespace game {

using CardmasterPointer = std::shared_ptr<plugin::Cardmaster>;

class Card : public Gamepiece
{
private:
    CardmasterPointer myMaster_;
public:
    Card();
    Card(const CardmasterPointer &myMaster);
    QString GetTraitText(QString trait){return myMaster_->GetTraitText((trait));}
};

} // namespace game

#endif // CARD_H