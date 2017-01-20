#include "deck.h"


Deck::Deck(): BaseObject()
{

}

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

