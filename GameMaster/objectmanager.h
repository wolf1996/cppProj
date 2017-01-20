#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H

#include <string>
#include <memory>
#include <map>
#include <iostream>


//#include <sol.hpp>

#include "configfile.h"
#include "primitives/all.h"

class ObjectManager
{
public:
    ObjectManager();
    void LoadVariables(const std::shared_ptr<ConfigFile>&);
    Deck& GetDeck(const std::string& deckname);
    Field& GetField(const std::string& );
    CardHolder& GetCardHolder(const std::string& );
    Player& GetPlayer(const std::string& );
    InfoBoard& GetInfoBoard(const std::string& );
    Player& GetTest(const std::string& name);
private:
    friend class ObjectBuilder;
    std::shared_ptr<ConfigFile> config_;
    std::map<std::string, CardHolder> card_holders_;
    std::map<std::string, Field> fields_;
    std::map<std::string, Player> players_;
    std::map<std::string, Deck> decks_;
    std::map<std::string, InfoBoard> info_boards_;
};

#endif // OBJECTMANAGER_H
