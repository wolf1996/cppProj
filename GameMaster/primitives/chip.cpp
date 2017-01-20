#include "chip.h"

Chip::Chip(): BaseObject(), position_(0)
{

}

Chip::Chip(bool visible): BaseObject(visible), position_(0)
{

}

void Chip::MoveForward(int num){
    position_ += num;
}

void Chip::SetPosition(unsigned int num){
    position_ = num;
}

unsigned int  Chip::GetPosition(){
    return position_;
}

void Chip::DeclarationToLua(sol::table &namespace_)
{
    sol::constructors<sol::types<>,sol::types<bool>> ctor;
    namespace_.new_usertype<Chip>("Chip",
                                        ctor,
                                        "isVisible",&Chip::isVisible,
                                        "MoveForvard",&Chip::MoveForward,
                                        "Position",sol::property(&Chip::GetPosition,&Chip::SetPosition)
                                        );
}
