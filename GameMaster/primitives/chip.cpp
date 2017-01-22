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

ChipPtr::ChipPtr(std::shared_ptr<Chip> chip): BaseObjectPtr(chip)
{
    this->chip_ = chip;
}

ChipPtr ChipPtr::Create(bool visible)
{
    if(this->chip_)
      return *this;
    this->chip_ = std::make_shared<Chip>(Chip(visible));
    return *this;
}

void ChipPtr::MoveForward(int num)
{
    this->chip_->MoveForward(num);
}

void ChipPtr::SetPosition(unsigned int num)
{
    this->chip_->SetPosition(num);
}

unsigned int ChipPtr::GetPosition()
{
    return this->chip_->GetPosition();
}

void ChipPtr::DeclarationToLua(sol::table &namespace_)
{
    namespace_.new_usertype<ChipPtr>("ChipPtr",
                                     "Create",&ChipPtr::Create,
                                     "isVisible",&ChipPtr::isVisible,
                                     "MoveForvard",&ChipPtr::MoveForward,
                                     "Position",sol::property(&ChipPtr::GetPosition,&ChipPtr::SetPosition)
                                     );
}
