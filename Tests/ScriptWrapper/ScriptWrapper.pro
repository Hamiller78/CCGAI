#-------------------------------------------------
#
# Project created by QtCreator 2018-01-14T18:14:14
#
#-------------------------------------------------

QT       += testlib

QT       -= gui

TARGET = tst_scriptwrappertest
CONFIG   += console
CONFIG   -= app_bundle

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
    ../../Prototype/exceptionplugin.cpp \
    ../../Prototype/pythonsetup.cpp \
        tst_scriptwrappertest.cpp 

DEFINES += SRCDIR=\\\"$$PWD/\\\"

win32:CONFIG(release, debug|release): LIBS += -L$$(PYTHONLIBS) -lpython36
else:win32:CONFIG(debug, debug|release): LIBS += -L$$(PYTHONLIBS) -lpython36_d

INCLUDEPATH += $$(PYTHONINCLUDE)
DEPENDPATH += $$(PYTHONINCLUDE)
