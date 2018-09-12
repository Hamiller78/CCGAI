QT += testlib
QT -= gui

TARGET = tst_gamelooptest

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  \
    tst_gamelooptest.cpp \
    ../../Prototype/board.cpp \
    ../../Prototype/card.cpp \
    ../../Prototype/cardmaster.cpp \
    ../../Prototype/cardpool.cpp \
    ../../Prototype/deck.cpp \
    ../../Prototype/exceptionplugin.cpp \
    ../../Prototype/gameloop.cpp \
    ../../Prototype/gamemove.cpp \
    ../../Prototype/gamepiece.cpp \
    ../../Prototype/gamestate.cpp \
    ../../Prototype/pile.cpp \
    ../../Prototype/rulebook.cpp \
    ../../Prototype/rulebookmock.cpp
