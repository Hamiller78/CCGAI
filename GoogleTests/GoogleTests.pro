include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

HEADERS += \
    tst_googletest.h

SOURCES += \
        main.cpp \
        ../Prototype/gamepiece.cpp \
        ../Prototype/pile.cpp \
        tst_pile.cpp
