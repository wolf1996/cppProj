#ifndef CARDHOLDER_H
#define CARDHOLDER_H

#include <vector>
#include <tuple>

#include "baseobject.h"
#include "card.h"

class CardHolder: public BaseObject
{
public:
    CardHolder();
    CardHolder(bool visible);
    static void DeclarationToLua(sol::table& namespace_);
    std::string GetIName(unsigned int index);
    Card& GetICard(unsigned int index);
    Card EraseICard(unsigned int index);
    void AddCard(std::string name, Card card);
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
    Card EraseICard(unsigned int index);
    void AddCard(std::string name, Card card);
private:
    std::shared_ptr<CardHolder> cardholder_;
};

#endif // CARDHOLDER_H
