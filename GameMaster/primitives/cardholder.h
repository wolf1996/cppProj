#ifndef CARDHOLDER_H
#define CARDHOLDER_H

#include <vector>
#include <tuple>
#include <algorithm>

#include "baseobject.h"
#include "card.h"
#include "deck.h"

class CardHolder: public BaseObject
{
public:
    CardHolder();
    CardHolder(bool visible);
    static void DeclarationToLua(sol::table& namespace_);
    std::string GetIName(unsigned int index);
    Card& GetICard(unsigned int index);
    void EraseICard(unsigned int index);
    void AddCard(const std::string& name, Card card);
    void Shuffle();
    void AddFromDeck(Deck& , unsigned int num = 1, const std::string& name = std::string("system"));
    void PopToDeck(Deck&, unsigned int num = 1);
private:
    std::vector<std::tuple<Card,std::string>> cards_;
};

class CardHolderPtr: public BaseObjectPtr
{
public:
    CardHolderPtr(std::shared_ptr<CardHolder> CH = std::make_shared<CardHolder>(NULL));
    CardHolderPtr Create(bool visible = false);
    static void DeclarationToLua(sol::table& namespace_);
    std::string GetIName(unsigned int index);
    CardPtr GetICard(unsigned int index);
    void EraseICard(unsigned int index);
    void AddCard(std::string name, CardPtr card);
private:
    std::shared_ptr<CardHolder> cardholder_;
};

#endif // CARDHOLDER_H
