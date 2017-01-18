#include "scriptmanager.h"

ScriptManager::ScriptManager()
{

}


void ScriptManager::ApplyConfig(const std::shared_ptr<ConfigFile> & config){
    config_ = config;
}
