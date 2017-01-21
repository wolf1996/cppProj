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

CardPtr::CardPtr(std::shared_ptr<Card> card): BaseObjectPtr(card)
{
    this->card_ = card;
}


CardPtr CardPtr::Create(bool visible)
{
    if(!this->card_.get())
        return *this;
    this->card_ = std::make_shared<Card>(new Card(visible));
    return *this;
}

void CardPtr::DeclarationToLua(sol::table &namespace_)
{
    namespace_.new_usertype<CardPtr>("CardPtr",
                                  "isVisible",&CardPtr::isVisible
                                     );
}

boost::filesystem::path CardPtr::GetFace()
{
    return this->card_->GetFace();
}

boost::filesystem::path CardPtr::GetBack()
{
    return this->card_->GetBack();
}

void CardPtr::SetFace(const boost::filesystem::path &face)
{
    this->card_->SetFace(face);
}

void CardPtr::SetBack(const boost::filesystem::path &back)
{
    this->card_->SetBack(back);
}

void CardPtr::Show(CardPtr::ShowType val)
{

}
