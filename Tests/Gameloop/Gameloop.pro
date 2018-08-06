QT += testlib
QT -= gui

TARGET = tst_gamelooptest

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  \
    ../../Prototype/deck.cpp \
    ../../Prototype/gameloop.cpp \
    ../../Prototype/gamestate.cpp \
    tst_gamelooptest.cpp
