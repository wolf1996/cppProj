#ifndef SCRIPTMANAGER_H
#define SCRIPTMANAGER_H

#include <memory>
#include <sol.hpp>
#include "configfile.h"

class ScriptManager
{
    std::shared_ptr<ConfigFile> config_;
public:
    ScriptManager();
    ScriptManager(const std::shared_ptr<ConfigFile>& config): config_(config){}
    void ApplyConfig(const std::shared_ptr<ConfigFile>&);
};

#endif // SCRIPTMANAGER_H
