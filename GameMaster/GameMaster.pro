TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp
INCLUDEPATH += Lua/Lua.5.2.0/src
INCLUDEPATH += LuaBridge
LIBS += -llua5.2
