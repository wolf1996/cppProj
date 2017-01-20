#ifndef MESSAGEBOX_H
#define MESSAGEBOX_H

#include <sol.hpp>

///// наследование от baseobject??????
class MessageBox
{
public:
    MessageBox();
    static void DeclarationToLua(sol::table& namespace_);
};

#endif // MESSAGEBOX_H
