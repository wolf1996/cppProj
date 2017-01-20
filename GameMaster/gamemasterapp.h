#ifndef GAMEMASTERAPP_H
#define GAMEMASTERAPP_H

#include <iostream>
#include <string>
#include <memory>

extern "C" {
    # include "lua.h"
    # include "lauxlib.h"
    # include "lualib.h"
}

#include "configfile.h"
#include "objectmanager.h"
#include "scriptmanager.h"




//Application base class
class GameMasterApp
{
    std::shared_ptr<ConfigFile> config_;
    std::shared_ptr<ObjectManager> object_manager_;
    std::shared_ptr<ScriptManager> script_manager_;
public:
    GameMasterApp();
    void LoadConfig(const std::string& filename);

};

#endif // GAMEMASTERAPP_H
