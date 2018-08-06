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

#include <QtTest>

// add necessary includes here

class Gameloop : public QObject
{
    Q_OBJECT

private:
    Gameloop *testLoop_;

public:
    Gameloop();
    ~Gameloop();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_case1();

};

Gameloop::Gameloop()
{

}

Gameloop::~Gameloop()
{

}

void Gameloop::initTestCase()
{
    testLoop_ = new Gameloop();
}

void Gameloop::cleanupTestCase()
{
    delete testLoop_;
}

void Gameloop::test_case1()
{

}

QTEST_APPLESS_MAIN(Gameloop)

#include "tst_gameloop.moc"
