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
                                        "SetName",&Player::SetName,
                                        "AddToCardHolder",&Player::AddToCardHolder,
                                        "PopFromCardHolder",&Player::PopFromCardHolder,
                                        "GetCardHolder",&Player::GetCardHolder,
                                        "MoveChip",&Player::MoveChip
                                      );
}

void Player::MoveChip(const std::string& fieldname, unsigned int num){
    chips_[fieldname]->MoveForward(num);
}

PlayerPtr::PlayerPtr(std::shared_ptr<Player> player) : BaseObjectPtr(player)
{
    this->player_ = player;
}

PlayerPtr PlayerPtr::Create()
{
    if(this->player_)
        return *this;
    this->player_ = std::make_shared<Player>(Player());
    return *this;
}

void PlayerPtr::GetChip(FieldPtr* field, const std::string& name)
{
    this->player_->GetChip(*field,name);
}

void PlayerPtr::SetName(const std::__cxx11::string &name)
{
    this->player_->SetName(name);
}

void PlayerPtr::DeclarationToLua(sol::table &namespace_)
{
    namespace_.new_usertype<PlayerPtr>("PlayerPtr",
                                       "Create",&PlayerPtr::Create,
                                       "GetChip",&PlayerPtr::GetChip,
                                       "SetName",&PlayerPtr::SetName,
                                       "AddToCardHolder",&PlayerPtr::AddToCardHolder,
                                       "PopFromCardHolder",&PlayerPtr::PopFromCardHolder,
                                       "GetCardHolder",&PlayerPtr::GetCardHolder,
                                       "MoveChip",&PlayerPtr::MoveChip
                                      );
}

void PlayerPtr::AddToCardHolder(const std::string& name, CardPtr& card)
{
    this->player_->AddToCardHolder(name,*card);
}

void PlayerPtr::PopFromCardHolder(const std::__cxx11::string &name, DeckPtr &deck, unsigned int index)
{
    this->player_->PopFromCardHolder(name,*deck,index);
}

void PlayerPtr::PopFromCardHolder(const std::__cxx11::string &name, CardHolderPtr &card_holder, unsigned int index)
{
    this->player_->PopFromCardHolder(name,*card_holder,index);
}

CardHolderPtr &PlayerPtr::GetCardHolder(const std::__cxx11::string &name)
{
    return CardHolderPtr(std::make_shared<CardHolder>(this->player_->GetCardHolder(name)));
}

void PlayerPtr::MoveChip(const std::__cxx11::string &field, unsigned int num)
{
    this->player_->MoveChip(field,num);
}
