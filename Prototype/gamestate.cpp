/* Copyright (c) 2018-2020 Torben Kneesch

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

#include "gamestate.h"

namespace game {

unsigned int GameState::numberOfPointCounters_ = 2;
unsigned int GameState::countInstances_ = 0;

GameState::GameState(Board& newBoard): board_(newBoard)
{
    pointCounters_ = new std::vector<int>(numberOfPointCounters_, 0);
    GameState::countInstances_++;
}

GameState::~GameState()
{
    GameState::countInstances_--;
    delete pointCounters_;
}

GameState::GameState(const GameState &sourceState) : board_(sourceState.board_)
{
    CopyPointCounters(sourceState);
    GameState::countInstances_++;
}

GameState &GameState::operator=(const GameState &otherState)
{
    if (this != &otherState)
    {
        board_ = Board(otherState.board_);
        CopyPointCounters(otherState);
    }
    return *this;
}

void GameState::SetNumberOfPointCounters(unsigned int newNumber)
{
    if (0 == GameState::countInstances_)
    {
        numberOfPointCounters_ = newNumber;
    }
    else
    {
        throw std::runtime_error("Attempt to change number of pointer counters in GameState class"
                                 " while objects are instantiated!");
    }
}

void GameState::AlterPoints(unsigned int pointIndex, int relativeValue)
{
    pointCounters_->at(pointIndex) = pointCounters_->at(pointIndex) + relativeValue;
}

int GameState::GetPoints(unsigned int pointIndex) const
{
    return pointCounters_->at(pointIndex);
}

void GameState::SetPoints(unsigned int pointIndex, int absoluteValue)
{
    pointCounters_->at(pointIndex) = absoluteValue;
}

void GameState::CopyPointCounters(const GameState &sourceState)
{
    if (nullptr != pointCounters_)
    {
        delete pointCounters_;
    }
    pointCounters_ = new std::vector<int>(*sourceState.pointCounters_);
}

} // namespace game
