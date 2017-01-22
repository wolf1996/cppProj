#include "scriptmanager.h"

ScriptManager::ScriptManager(const std::shared_ptr<ConfigFile> &config): config_(config)
{
    this->lua.open_libraries(sol::lib::base, sol::lib::io);
    this->namespace_ = this->lua.create_named_table("objects");
    this->init = this->lua["init"];
    this->main = this->lua["main"];
}

void ScriptManager::
LoadObject()
{
    Card::DeclarationToLua(this->namespace_);
    CardHolder::DeclarationToLua(this->namespace_);
    Chip::DeclarationToLua(this->namespace_);
    Deck::DeclarationToLua(this->namespace_);
    Field::DeclarationToLua(this->namespace_);
    InfoBoard::DeclarationToLua(this->namespace_);
}

void ScriptManager::CallInit()
{
    this->init();
}

void ScriptManager::CallMain()
{
    this->main();
}

void ScriptManager::LoadScript()
{
    this->lua.load((*this->config_).GetCodeFileName());
}
