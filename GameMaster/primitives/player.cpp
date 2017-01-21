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

void Player::AddToCardHolder(const std::string& name, Card& card){
    card_holders_[name].AddCard(std::string("system"),card);
}

void Player::PopFromCardHolder(const std::string& name, Deck& deck, unsigned int index){
    deck.AppendCards(std::vector<Card>(1,card_holders_[name].GetICard(index)));
    card_holders_[name].EraseICard(index);
}

void Player::PopFromCardHolder(const std::string& name, CardHolder& card_holder, unsigned int index){
    card_holder.AddCard(name_,card_holders_[name].GetICard(index));
    card_holders_[name].EraseICard(index);
}

CardHolder& Player::GetCardHolder(const std::string& name){
    return card_holders_[name];
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
