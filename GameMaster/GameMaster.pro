TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    gamemasterapp.cpp \
    configfile.cpp \
    configfilelua.cpp \
    objectmanager.cpp \
    player.cpp \
    primitives/field.cpp \
    primitives/player.cpp
INCLUDEPATH += LuaBridge
LIBS += -llua5.2

HEADERS += \
    gamemasterapp.h \
    configfile.h \
    configfilelua.h \
    objectmanager.h \
    field.h \
    player.h \
    primitives/field.h \
    primitives/player.h
