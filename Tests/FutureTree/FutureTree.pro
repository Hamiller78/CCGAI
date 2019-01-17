QT += testlib
QT -= gui

TARGET = tst_futuretreetest

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += \ 
    ../../Prototype/futuretree.cpp \
    ../../Prototype/gamemovemock.cpp \
    ../../Prototype/gamestate.cpp \
    ../../Prototype/rulebookmock.cpp \
    ../../Prototype/stateanalyzermock.cpp \
    tst_futuretreetest.cpp
