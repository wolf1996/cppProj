#include "objectmanager.h"

ObjectManager::ObjectManager():config_(NULL)
{

}

void ObjectManager::LoadVariables(const std::shared_ptr<ConfigFile>& config){
    config_ = config;
}
