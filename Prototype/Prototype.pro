#-------------------------------------------------
#
# Project created by QtCreator 2017-11-14T19:48:27
#
#-------------------------------------------------

QT       += core gui qml
CONFIG += c++11
CONFIG += no_keywords

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Prototype
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    IoHelper/ioexception.cpp \
    IoHelper/textfileloader.cpp \
    Scripting/jsscriptwrapper.cpp \
    gamepiececard.cpp \
    main.cpp \
    mainwindow.cpp \
    board.cpp \
    gamemove.cpp \
    pile.cpp \
    gamemovemovepile.cpp \
    gamemovespawnpiece.cpp \
    gamemovemovetop.cpp \
    plugin.cpp \
    cardpool.cpp \
    exceptionplugin.cpp \
    cardmaster.cpp \
    deck.cpp \
    rulebook.cpp \
    gameloop.cpp \
    gamestate.cpp \
    playeragent.cpp

HEADERS += \
    IoHelper/ioexception.h \
    IoHelper/textfileloader.h \
    Scripting/iscriptwrapper.h \
    Scripting/jsscriptwrapper.h \
    gamepiececard.h \
    iboard.h \
    igamepiece.h \
    igamestate.h \
    mainwindow.h \
    board.h \
    gamemove.h \
    objfactory.h \
    pile.h \
    gamemovemovepile.h \
    gamemovespawnpiece.h \
    gamemovemovetop.h \
    plugin.h \
    cardpool.h \
    exceptionplugin.h \
    cardmaster.h \
    deck.h \
    rulebook.h \
    gameloop.h \
    gamestate.h \
    playeragent.h

FORMS += \
        mainwindow.ui
