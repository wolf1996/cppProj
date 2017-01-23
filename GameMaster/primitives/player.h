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
    void MoveChip(const std::string& field, unsigned int num);
private:
    std::map<std::string, CardHolder> card_holders_;
    std::map<std::string, std::shared_ptr<Chip>> chips_;
    std::map<std::string, Deck> decks_;
    std::string name_;
};

class PlayerPtr
{
public:
    PlayerPtr(std::shared_ptr<Player> player = std::make_shared<Player>(NULL));
    PlayerPtr Create();
    void GetChip(FieldPtr field, const std::string& name);
    const char *GetTest(const std::string& name);
    void SetName(const std::string& name);
    static void DeclarationToLua(sol::table& namespace_);
    void AddToCardHolder(const std::string&name, CardPtr & card);
    void PopFromCardHolder(const std::string& name, DeckPtr& deck, unsigned int index);
    void PopFromCardHolder(const std::string& name, CardHolderPtr& card_holder, unsigned int index);
    CardHolderPtr& GetCardHolder(const std::string& name);
    void MoveChip(const std::string& field, unsigned int num);
private:
    std::shared_ptr<Player> player_;
};

#endif // PLAYER_H
