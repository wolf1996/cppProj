#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <memory>
#include <map>

#include <iostream>
#include <sol.hpp>

#include "chip.h"
#include "cardholder.h"
#include "field.h"
#include "deck.h"


class Player
{
public:
    Player();
    void GetChip(Field*, const std::string& name);
    const char *GetTest(const std::string& name);
    void SetName(const std::string& name);
    static void DeclarationToLua(sol::table& namespace_);
    void AddToCardHolder(const std::string&, Card& );
    void PopFromCardHolder(const std::string& name, Deck& deck, unsigned int index);
    void PopFromCardHolder(const std::string& name, CardHolder& deck, unsigned int index);
    CardHolder& GetCardHolder(const std::string& name);
private:
    std::map<std::string, CardHolder> card_holders_;
    std::map<std::string, std::shared_ptr<Chip>> chips_;
    std::map<std::string, Deck> decks_;
    std::string name_;
};

#endif // PLAYER_H
