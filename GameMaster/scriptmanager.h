#ifndef SCRIPTMANAGER_H
#define SCRIPTMANAGER_H

#include <memory>
#include <sol.hpp>
#include "configfile.h"
#include <primitives/all.h>

class ScriptManager
{
    std::shared_ptr<ConfigFile> config_;
    sol::state lua;
    sol::table namespace_;
public:
    ScriptManager(const std::shared_ptr<ConfigFile>& config);
    void LoadObject(void);
    void LoadScript(void);
};

#endif // SCRIPTMANAGER_H
