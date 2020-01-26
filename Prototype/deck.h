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

#ifndef DECK_H
#define DECK_H

#include <QFile>
#include <QTextStream>

#include <vector>

namespace plugin {

class Deck
{
private:
    std::vector<QStringList> deckLists_;
    QStringList deckNames_;
public:
    Deck();
    const std::vector<QStringList>& GetDeckLists() const {return deckLists_;}
    const QStringList& GetDeckNames() const {return deckNames_;}
    void LoadDecklistFromTxt(const QString& deckFileName);
    void ParseTxtTextstream(QTextStream &fileContent);
private:
    void AddCards(const QString& txtLine);
    void AddSidedeck(const QString& sideDeckName);
    void ClearDeck();
};

} // namepace plugin

#endif // DECK_H
