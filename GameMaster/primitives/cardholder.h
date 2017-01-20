#ifndef CARDHOLDER_H
#define CARDHOLDER_H

#include <vector>

#include "baseobject.h"
#include "card.h"

class CardHolder: public BaseObject
{
public:
    CardHolder();
    CardHolder(bool visible);
    static void DeclarationToLua(sol::table& namespace_);

private:
    std::vector<std::tuple<Card,std::string>> cards_;
};

#endif // CARDHOLDER_H
