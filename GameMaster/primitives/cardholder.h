#ifndef CARDHOLDER_H
#define CARDHOLDER_H
#include "baseobject.h"


class CardHolder: public BaseObject
{
public:
    CardHolder();
    CardHolder(bool visible);
    bool isVisible() override;
    static void DeclarationToLua(lua_State* L);
private:
    bool _visible;
};

#endif // CARDHOLDER_H
