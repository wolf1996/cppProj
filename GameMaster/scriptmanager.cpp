#include "scriptmanager.h"

void ScriptManager::LoadLibries_()
{
    this->lua.open_libraries(sol::lib::base, sol::lib::io);
}

ScriptManager::ScriptManager()
{

}



void ScriptManager::ApplyConfig(const std::shared_ptr<ConfigFile> & config){
    config_ = config;

}

void ScriptManager::LoadScript()
{

}
