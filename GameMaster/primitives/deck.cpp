#include "deck.h"

Deck::Deck(bool visible): BaseObject(visible)
{

}

std::vector<Card> Deck::PopCards(int num){
    std::vector<Card> result(cards_.end()-num, cards_.end());
    cards_.erase(cards_.end()-num, cards_.end());
    return result;
}

void Deck::AppendCards(std::vector<Card> cards){
    cards_.insert(cards_.end(),cards.begin(),cards.end());
}

void Deck::Shuffle(){
    std::random_shuffle(cards_.begin(), cards_.end());
}

void Deck::DeclarationToLua(sol::table &namespace_)
{
    sol::constructors<sol::types<>,sol::types<bool>> ctor;
    namespace_.new_usertype<Deck>("Deck",
                                        ctor,
                                        "isVisible",&Deck::isVisible,
                                        "PopCards",&Deck::PopCards,
                                        "AppendCards",&Deck::AppendCards,
                                        "Shuffle",&Deck::Shuffle
                                        );
}
int Deck::size(){
    cards_.size();
}


DeckPtr::DeckPtr(std::shared_ptr<Deck> deck) : BaseObjectPtr(deck)
{
    this->deck_ = deck;
}

DeckPtr DeckPtr::Create(bool visible)
{
    if(this->deck_)
        return *this;
    this->deck_ = std::make_shared<Deck>(Deck(visible));
    return *this;
}

std::vector<CardPtr> DeckPtr::PopCards(int num)
{
    auto pop_cards = this->deck_->PopCards(num);
    std::vector<CardPtr> result(pop_cards.size());
    for(auto it = pop_cards.begin(); it != pop_cards.end(); ++it)
        result.push_back(CardPtr(std::make_shared<Card>(*it)));
    return result;
}

void DeckPtr::AppendCards(std::vector<CardPtr> cards)
{
    std::vector<Card> result(cards.size());
    for(auto it = cards.begin(); it != cards.end(); ++it)
        result.push_back(**it);
    this->deck_->AppendCards(result);
}
