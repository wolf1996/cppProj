#ifndef GAMEMASTERAPP_H
#define GAMEMASTERAPP_H

#include <iostream>
#include <string>
#include <memory>

#include <LuaBridge.h>

#include "configfile.h"

extern "C" {
    # include "lua.h"
    # include "lauxlib.h"
    # include "lualib.h"
}


//Application base class
class GameMasterApp
{
    std::shared_ptr<ConfigFile> config_;
public:
    GameMasterApp();
    void OpenConfig(const std::string& filename);
};

#endif // GAMEMASTERAPP_H
