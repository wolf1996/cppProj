#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H

using namespace std;
#include <string>
#include <memory>
#include <map>
#include <iostream>

#include "configfile.h"
#include "primitives/all.h"

class ObjectManager
{   std::shared_ptr<ConfigFile> config_;
    std::map<std::string, CardHolder> card_holders_;
    std::map<std::string, Field> fields_;
    std::map<std::string, Player> players_;
    std::map<std::string, Deck> decks_;
    std::map<std::string, InfoBoard> boards_;
public:
    ObjectManager();
    void LoadVariables(const std::shared_ptr<ConfigFile>&);
    //    Deck& GetDeck(const std::string& deckname);
    //    Field& GetField(const std::string& );
    //    CardHolder& GetCardHolder(const std::string& );
    //    Player& GetPlayer(const std::string& );
    //    InfoBoard& GetInfoBoard(const std::string& );
    Player& GetTest(const std::string& name);
};

#endif // OBJECTMANAGER_H
