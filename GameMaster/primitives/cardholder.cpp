#include "cardholder.h"

CardHolder::CardHolder(): BaseObject()
{

}

CardHolder::CardHolder(bool visible): BaseObject(visible)
{

}

void CardHolder::DeclarationToLua(sol::table& namespace_)
{
    sol::constructors<sol::types<>,sol::types<bool>> ctor;
    namespace_.new_usertype<CardHolder>("CardHolder",
                                        ctor,
                                        "isVisible",&CardHolder::isVisible
                                        );
}

void CardHolder::AddFromDeck(Deck& deck, unsigned int num, const std::string& name){
    for (auto x:deck.PopCards(num)){
        AddCard(name,x);
    }
}

void CardHolder::PopToDeck(Deck& deck, unsigned int index){
     deck.AppendCards(std::vector<Card>(1,std::get<0>(cards_[index])));
     EraseICard(index);
}

void CardHolder::Shuffle(){
    std::random_shuffle(cards_.begin(), cards_.end());
}


std::string CardHolder::GetIName(unsigned int index){
    return std::get<1>(cards_[index]);
}

Card& CardHolder::GetICard(unsigned int index){
    return std::get<0>(cards_[index]);
}


void CardHolder::EraseICard(unsigned int index){
      cards_.erase(cards_.begin()+index);
}

void CardHolder::AddCard(const std::string &name, Card val){
    cards_.push_back(std::tuple<Card, std::string>(val,name));
}

CardHolderPtr::CardHolderPtr(std::shared_ptr<CardHolder> CH): BaseObjectPtr(CH)
{
    this->cardholder_ = CH;
}

CardHolderPtr CardHolderPtr::Create(bool visible)
{
    if(this->cardholder_)
        return *this;
    this->cardholder_ = std::make_shared<CardHolder>(CardHolder(visible));
    return *this;
}

void CardHolderPtr::DeclarationToLua(sol::table &namespace_)
{
    namespace_.new_usertype<CardHolderPtr>("CardHolderPtr",
                                           "isVisible",&CardHolderPtr::isVisible,
                                           "GetIName",&CardHolderPtr::GetIName,
                                           "GetICard",&CardHolderPtr::GetICard,
                                           "EraseICard",&CardHolderPtr::EraseICard,
                                           "AddCard",&CardHolderPtr::AddCard,
                                           "Create",&CardHolderPtr::Create
                                           );
}

std::__cxx11::string CardHolderPtr::GetIName(unsigned int index)
{
    return this->cardholder_->GetIName(index);
}

CardPtr CardHolderPtr::GetICard(unsigned int index)
{
    auto ptr_card = &(this->cardholder_->GetICard(index));
    return CardPtr(std::make_shared<Card>(ptr_card));
}

void CardHolderPtr::EraseICard(unsigned int index)
{
    this->cardholder_->EraseICard(index);
}

void CardHolderPtr::AddCard(std::__cxx11::string name, CardPtr card)
{
    this->cardholder_->AddCard(name,*(card.card_));
}
