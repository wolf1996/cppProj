#ifndef DECK_H
#define DECK_H

#include <vector>
#include <algorithm>

#include "card.h"

class Deck
{
public:
    Deck();
    std::vector<Card> PopCards(int num = 1);
    void AppendCards(std::vector<Card> cards);
    void Shuffle();
private:
    std::vector<Card> cards_;

};

#endif // DECK_H
