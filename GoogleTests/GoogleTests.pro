include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += thread
# CONFIG -= qt

HEADERS += \
    IoHelper/MockTextfileLoader.h \
    MockBoard.h \
    MockCardpool.h \
    MockGamepiece.h \
    MockPile.h \
    MockPileFactory.h \
    tst_googletest.h

SOURCES += \
        main.cpp \
        tst_board.cpp \
        tst_deck.cpp \
        tst_gamestate.cpp \
        tst_pile.cpp \
        tst_plugin.cpp

SOURCES += \
        ../Prototype/IoHelper/ioexception.cpp \
        ../Prototype/IoHelper/textfileloader.cpp \
        ../Prototype/board.cpp \
        ../Prototype/cardmaster.cpp \
        ../Prototype/cardpool.cpp \
        ../Prototype/deck.cpp \
        ../Prototype/exceptionplugin.cpp \
        ../Prototype/gamepiececard.cpp \
        ../Prototype/pile.cpp \
        ../Prototype/plugin.cpp
