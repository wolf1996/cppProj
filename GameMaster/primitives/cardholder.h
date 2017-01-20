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
    bool isVisible() override;
    //void GetCardFromDeck(const std::string& deckname, unsigned int num);
//    static void DeclarationToLua(luabridge::lua_State* L);
private:
    std::vector<std::tuple<Card,std::string>> cards_;
    bool _visible;
};

#endif // CARDHOLDER_H
