include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

HEADERS += \
    MockGamepiece.h \
    MockPile.h \
    MockPileFactory.h \
    tst_googletest.h

SOURCES += \
        main.cpp \
        tst_board.cpp \
        tst_pile.cpp

SOURCES += \
        ../Prototype/board.cpp \
        ../Prototype/pile.cpp \
