// main.cpp
//
// TODO: base object
#include <QtGui>
#include <QtCore>
#include <QWidget>
#include <QApplication>
#include <iostream>
#include <sol.hpp>
#include "gamemasterapp.h"

extern "C" {
    # include "lua.h"
    # include "lauxlib.h"
    # include "lualib.h"
}

int main(int argc,char** argv)
{
    std::string config_file_name("WWWWWWWWWWWWWWWWWWWWWWW");
    GameMasterApp  app;
    app.LoadConfig(config_file_name);


    QApplication w(argc,argv);
    QWidget wgt;
    wgt.setWindowTitle("GameMaster");
    wgt.show();
    return w.exec();
}
