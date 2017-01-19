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

void CardHolder::DeclarationToLua(luabridge::lua_State *L)
{
    luabridge::getGlobalNamespace(L)
            .beginNamespace("Objects")
                .deriveClass<CardHolder,BaseObject>("CardHolder")
                    .addConstructor<void(*)(void)>()
                    .addConstructor<void(*)(bool visible)>()
                    .addFunction("isVisible",&CardHolder::isVisible)
                .endClass()
            .endNamespace();
}
