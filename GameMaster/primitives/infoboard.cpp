#include "infoboard.h"

InfoBoard::InfoBoard(): BaseObject()
{

}

InfoBoard::InfoBoard(bool visible): BaseObject(visible)
{

}

void InfoBoard::DeclarationToLua(sol::table &namespace_)
{
    sol::constructors<sol::types<>,sol::types<bool>> ctor;
    namespace_.new_usertype<InfoBoard>("Infoboard",
                                        ctor,
                                        "isVisible",&InfoBoard::isVisible
                                      );
}


void InfoBoard::SetText(const std::string& text){
    text_ = text;
}

std::string InfoBoard::GetText(){
    return text_;
}

void InfoBoard::Show(){

}
