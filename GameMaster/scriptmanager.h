#ifndef SCRIPTMANAGER_H
#define SCRIPTMANAGER_H

#include <memory>

#include "configfile.h"


class ScriptManager
{
    std::shared_ptr<ConfigFile> config_;
public:
    ScriptManager();
    void ApplyConfig(const std::shared_ptr<ConfigFile>&);
};

#endif // SCRIPTMANAGER_H
