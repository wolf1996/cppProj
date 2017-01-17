#ifndef GAMEMASTERAPP_H
#define GAMEMASTERAPP_H

#include <iostream>
#include <string>
#include <memory>

#include <LuaBridge.h>

#include "configfile.h"
#include "objectmanager.h"

extern "C" {
    # include "lua.h"
    # include "lauxlib.h"
    # include "lualib.h"
}


//Application base class
class GameMasterApp
{
    std::shared_ptr<ConfigFile> config_;
    ObjectManager object_manager_;
public:
    GameMasterApp();
    void LoadConfig(const std::string& filename);
};

#endif // GAMEMASTERAPP_H
