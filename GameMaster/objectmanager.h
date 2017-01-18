#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H

#include <string>
#include <memory>
#include <map>

#include "configfile.h"
#include "primitives/all.h"

class ObjectManager
{   std::shared_ptr<ConfigFile> config_;
    std::map<std::string, CardHolder> card_holders_;
    std::map<std::string, Field> fields_;
    std::map<std::string, Player> players_;
    std::map<std::string, Deck> decks_;
public:
    ObjectManager();
    void LoadVariables(const std::shared_ptr<ConfigFile>&);
};

#endif // OBJECTMANAGER_H
