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
    Card GetICard(unsigned int index);
    Card EraseICard(unsigned int index);
    void AddCard(std::string name, Card card);
private:
    std::vector<std::tuple<Card,std::string>> cards_;
};

#endif // CARDHOLDER_H
