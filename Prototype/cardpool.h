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

#ifndef CARDPOOL_H
#define CARDPOOL_H

#include <QStringList>

#include "cardmaster.h"
#include "exceptionplugin.h"

namespace plugin {

class Cardpool
{
private:
    std::vector<Cardmaster*> listOfCards_;
    QStringList namesOfColumns_;
public:
    Cardpool();
    void setPool(const QStringList& lackeyCardData);
private:
    void parseHeader(const QString& headerLine);
    void makeCardmasters(const QStringList& lackeyCardData);
};

} // namespace plugin

#endif // CARDPOOL_H
