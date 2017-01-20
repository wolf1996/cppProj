#include "cardholder.h"

CardHolder::CardHolder(): BaseObject()
{

}

CardHolder::CardHolder(bool visible): BaseObject(visible)
{

}

void CardHolder::DeclarationToLua(sol::table& namespace_)
{
    sol::constructors<sol::types<>,sol::types<bool>> ctor;
    namespace_.new_usertype<CardHolder>("CardHolder",
                                        ctor,
                                        "isVisible",&CardHolder::isVisible
                                        );
}

