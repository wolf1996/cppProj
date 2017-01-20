#ifndef SCRIPTMANAGER_H
#define SCRIPTMANAGER_H

#include <memory>
#include <sol.hpp>
#include "configfile.h"

class ScriptManager
{
    std::shared_ptr<ConfigFile> config_;
    sol::state lua;
public:
    ScriptManager(const std::shared_ptr<ConfigFile>& config);
    void LoadObject(void);
    void LoadScript(void);
};

#endif // SCRIPTMANAGER_H
