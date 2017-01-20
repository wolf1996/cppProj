#include "card.h"

Card::Card(): BaseObject()
{

}

Card::Card(bool visible): BaseObject(visible)
{

}

void Card::DeclarationToLua(sol::table &namespace_)
{
    sol::constructors<sol::types<>,sol::types<bool>> ctor;
    namespace_.new_usertype<Card>("Card",
                                        ctor,
                                        "isVisible",&Card::isVisible
                                        );
}
