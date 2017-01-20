#include "player.h"

Player::Player():name_(std::string(""))
{

}
const char* Player::GetTest(const std::string& name){
    std::cout<< "call player_test with value: " << name << std::endl;
    std::string var = name;
   return "var";
}

void Player::GetChip(Field* field, const std::string& name){
    chips_[name] = field->GetChip(name_);
}

void Player::SetName(const std::string& name){
    name_ = name;
}

void Player::DeclarationToLua(sol::table &namespace_)
{
    sol::constructors<sol::types<>> ctor;
    namespace_.new_usertype<Player>("Player",
                                        ctor,
                                        "GetChip",&Player::GetChip,
                                        "SetName",&Player::SetName
                                      );
}
