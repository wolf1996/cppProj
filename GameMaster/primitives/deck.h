#ifndef DECK_H
#define DECK_H

#include <vector>
#include <algorithm>
#include "baseobject.h"
#include "card.h"

class Deck : public BaseObject
{
public:
    Deck();
    Deck(bool visible);
    std::vector<Card> PopCards(int num = 1);//add
    void AppendCards(std::vector<Card> cards);//add
    void Shuffle();//add
    static void DeclarationToLua(sol::table& namespace_);
private:
    std::vector<Card> cards_;

};

#endif // DECK_H
