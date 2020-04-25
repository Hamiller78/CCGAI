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

#ifndef OBJFACTORY_H
#define OBJFACTORY_H


template <class T, typename ... Args>
class ObjFactory
{
public:
    virtual ~ObjFactory() {}
    virtual T* CreatePtr(Args&& ... args) const {return new T(std::forward<Args>(args) ...);}
//    virtual T Create(Args&& ... args) const {return T(std::forward<Args>(args) ...);}
};

#endif // OBJFACTORY_H
