#include "messagebox.h"

MessageBox::MessageBox()
{

}

void MessageBox::DeclarationToLua(sol::table &namespace_)
{

    sol::constructors<sol::types<>> ctor;
    namespace_.new_usertype<MessageBox>("MessageBox",
                                        ctor
                                      );
}
