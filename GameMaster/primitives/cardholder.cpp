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


std::string CardHolder::GetIName(unsigned int index){
    return std::get<1>(cards_[index]);
}

Card CardHolder::GetICard(unsigned int index){
    return std::get<0>(cards_[index]);
}

Card  CardHolder::EraseICard(unsigned int index){
      return std::get<0>(*cards_.erase(cards_.begin()+index));
}

void CardHolder::AddCard(std::string name, Card val){
    cards_.push_back(std::tuple<Card, std::string>(val,name));
}
