#include "objectmanager.h"

ObjectManager::ObjectManager():config_(NULL)
{
    std::cout<<"Create ObjectManager"<<std::endl;
}

void ObjectManager::LoadVariables(const std::shared_ptr<ConfigFile>& config){
    config_ = config;
}

Player& ObjectManager::GetTest(const std::string& name){
    std::cout << "call obj_test" << std::endl;
   static Player pl;
   return pl;
}

Deck& ObjectManager::GetDeck(const std::string& name){
    auto result = decks_.find(name);
    return result->second;
}

Field& ObjectManager::GetField(const std::string& name){
    auto result = fields_.find(name);
    return result->second;
}

CardHolder& ObjectManager::GetCardHolder(const std::string& name){
    auto result = card_holders_.find(name);
    return result->second;
}

Player& ObjectManager::GetPlayer(const std::string& name){
    auto result = players_.find(name);
    return result->second;
}

InfoBoard& ObjectManager::GetInfoBoard(const std::string& name){
    auto result = info_boards_.find(name);
    return result->second;
}
