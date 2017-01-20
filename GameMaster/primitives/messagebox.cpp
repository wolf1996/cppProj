#include "messagebox.h"

MessageBox::MessageBox()
{

}
<<<<<<< HEAD

void MessageBox::DeclarationToLua(sol::table &namespace_)
{

    sol::constructors<sol::types<>> ctor;
    namespace_.new_usertype<MessageBox>("MessageBox",
                                        ctor
                                      );
=======
void MessageBox::SetText(const std::string& text){
    text_ = text;
}

std::string MessageBox::GetText(){
    return text_;
}

void MessageBox::Show(){

>>>>>>> 7085158836ea40d2741ef870a6a4cd928be0e28f
}
