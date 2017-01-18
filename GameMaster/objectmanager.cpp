#include "objectmanager.h"

ObjectManager::ObjectManager():config_(NULL)
{
    std::cout<<"Create ObjectManager"<<std::endl;
}

void ObjectManager::LoadVariables(const std::shared_ptr<ConfigFile>& config){
    config_ = config;
}

Player& ObjectManager::GetTest(const std::string& name){
    std::cout << "call obj_test" << endl;
   static Player pl;
   return pl;
}
