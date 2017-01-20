#include "scriptmanager.h"

ScriptManager::ScriptManager(const std::shared_ptr<ConfigFile> &config): config_(config)
{
    this->lua.open_libraries(sol::lib::base, sol::lib::io);
    this->namespace_ = this->lua.create_named_table("objects");
}

void ScriptManager::LoadObject()
{
    CardHolder::DeclarationToLua(this->namespace_);
}

void ScriptManager::LoadScript()
{
    this->lua.load((*this->config_).GetCodeFileName());
}
