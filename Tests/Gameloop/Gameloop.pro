QT += testlib
QT -= gui

TARGET = tst_gamelooptest

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  \
    tst_gamelooptest.cpp \
    ../../Prototype/board.cpp \
    ../../Prototype/gameloop.cpp \
    ../../Prototype/gamemove.cpp \
    ../../Prototype/gamestate.cpp \
    ../../Prototype/gamestatemock.cpp \
    ../../Prototype/rulebook.cpp \
    ../../Prototype/rulebookmock.cpp
