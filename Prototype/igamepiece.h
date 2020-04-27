/* Copyright (c) 2017-2020 Torben Kneesch

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

#ifndef IGAMEPIECE_H
#define IGAMEPIECE_H

#include <memory>

#include <QString>
#include <QStringList>

namespace game {

class IGamepiece
{
public:
    virtual ~IGamepiece() {}

    virtual std::shared_ptr<IGamepiece> Clone() const = 0;

    virtual void SetTraits(const QString& cardData, const QStringList& dataColumnTitles) = 0;
    virtual QString GetTraitText(const QString& trait) const = 0;
};

} // namespace game

#endif // IGAMEPIECE_H
