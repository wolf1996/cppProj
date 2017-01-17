#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H

#include <string>
#include <memory>

#include "configfile.h"

class ObjectManager
{   std::shared_ptr<ConfigFile> config_;
public:
    ObjectManager();
    void LoadVariables(const std::shared_ptr<ConfigFile>&);
};

#endif // OBJECTMANAGER_H
