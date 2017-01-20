#include "messagebox.h"

MessageBox::MessageBox()
{

}

void MessageBox::DeclarationToLua(sol::table &namespace_)
{

    sol::constructors<sol::types<>> ctor;
    namespace_.new_usertype<MessageBox>("MessageBox",
                                        ctor,
                                        "Text",sol::property(&MessageBox::GetText,&MessageBox::SetText),
                                        "Show",&MessageBox::Show
                                      );
}
void MessageBox::SetText(const std::string& text){
    text_ = text;
}

std::string MessageBox::GetText(){
    return text_;
}

void MessageBox::Show(){

}
