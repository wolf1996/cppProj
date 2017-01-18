#include "objectmanager.h"

ObjectManager::ObjectManager():config_(NULL)
{

}

void ObjectManager::LoadVariables(const std::shared_ptr<ConfigFile>& config){
    config_ = config;
}

Player& ObjectManager::GetTest(const std::string& name){
   static Player pl;
   return pl;
}
