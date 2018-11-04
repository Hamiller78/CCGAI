QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_gamestatetest.cpp \
    ../../Prototype/board.cpp \
    ../../Prototype/gamestate.cpp \
    ../../Prototype/pile.cpp
