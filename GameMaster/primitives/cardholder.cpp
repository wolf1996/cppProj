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

static void CardHolder::DeclarationToLua(lua_State *L)
{
    getGlobalNamespace(L)
            .beginNamespace("Objects")
                .beginClass<CardHolder,BaseObject>("CardHolder")
                    .addConstructor<void(*)(void)>()
                    .addConstructor<void(*)(bool visible)>()
                    .addFunction("isVisible",&CardHolder::isVisible)
                .endClass()
            .endNamespace();
}
