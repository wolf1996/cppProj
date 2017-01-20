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

boost::filesystem::path Card::GetFace(){
    return face_;
}

boost::filesystem::path Card::GetBack(){
    return back_;
}

void Card::SetFace(const boost::filesystem::path& face){
    face_ = face;
}

void Card::SetBack(const boost::filesystem::path& back){
    back_ = back;
}

void Card::Show(ShowType val){

}
