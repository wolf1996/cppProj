TEMPLATE = app
CONFIG += console c++14
CONFIG -= app_bundle
CONFIG += qt
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
TARGET = GameMaster
SOURCES += main.cpp \
    gamemasterapp.cpp \
    configfile.cpp \
    configfilelua.cpp \
    objectmanager.cpp \
    primitives/field.cpp \
    primitives/cardholder.cpp \
    primitives/deck.cpp \
    scriptmanager.cpp \
    primitives/chip.cpp \
    primitives/infoboard.cpp \
    primitives/baseobject.cpp \
    primitives/card.cpp \
    tablebuilder.cpp
INCLUDEPATH += Lua/Lua.5.2.0/src
INCLUDEPATH += single/sol
LIBS += -llua5.2\
        -lboost_system\
        -lboost_filesystem\


HEADERS += \
    gamemasterapp.h \
    configfile.h \
    configfilelua.h \
    objectmanager.h \
    primitives/field.h \
    primitives/cardholder.h \
    primitives/deck.h \
    scriptmanager.h \
    primitives/all.h \
    primitives/chip.h \
    primitives/infoboard.h \
    primitives/baseobject.h \
    primitives/card.h \
    tablebuilder.h

DISTFILES += \
    ../script.lua

