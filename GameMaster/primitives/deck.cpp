#include "deck.h"

Deck::Deck()
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
