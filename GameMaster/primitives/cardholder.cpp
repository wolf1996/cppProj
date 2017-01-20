#include "cardholder.h"

CardHolder::CardHolder()
{
    this->_visible = false;
}

CardHolder::CardHolder(bool visible)
{
    this->_visible = visible;
}

bool CardHolder::isVisible()
{
    return this->_visible;
}

//void CardHolder::DeclarationToLua(luabridge::lua_State *L)
//{
//}
