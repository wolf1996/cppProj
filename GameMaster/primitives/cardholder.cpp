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

void CardHolder::DeclarationToLua(sol::table& namespace_)
{
    sol::constructors<sol::types<>,sol::types<bool>> ctor;
    namespace_.new_usertype<CardHolder>("CardHolder",
                                        ctor,
                                        "isVisible",&CardHolder::isVisible
                                        );
}

