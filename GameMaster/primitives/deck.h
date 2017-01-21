#ifndef DECK_H
#define DECK_H

#include <vector>
#include <algorithm>
#include "baseobject.h"
#include "card.h"

class Deck : public BaseObject
{
public:
    Deck(bool visible = false);
    std::vector<Card> PopCards(int num = 1);//add
    void AppendCards(std::vector<Card> cards);//add
    void Shuffle();//add
    static void DeclarationToLua(sol::table& namespace_);
    int size();
private:
    std::vector<Card> cards_;

};

class DeckPtr: public BaseObjectPtr
{
public:
    DeckPtr(std::shared_ptr<Deck> deck = std::make_shared<Deck>(NULL));
    DeckPtr Create(bool visible = false);
    std::vector<CardPtr> PopCards(int num = 1);//add
    void AppendCards(std::vector<CardPtr> cards);//add
    void Shuffle();//add
    static void DeclarationToLua(sol::table& namespace_);
private:
    std::shared_ptr<Deck> deck_;
};

#endif // DECK_H
