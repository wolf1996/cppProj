#ifndef CARD_H
#define CARD_H

#include "boost/filesystem/path.hpp"
#include "baseobject.h"

///for CardPtr frendship
class CardHolderPtr;


class Card : public BaseObject
{
public:
    enum ShowType{
        BACK,
        FACE,
    };
    Card();
    Card(bool visible);
    static void DeclarationToLua(sol::table& namespace_);
    boost::filesystem::path GetFace();
    boost::filesystem::path GetBack();
    void SetFace(const boost::filesystem::path&);
    void SetBack(const boost::filesystem::path&);
    void Show(ShowType val = BACK);
private:
    boost::filesystem::path face_;
    boost::filesystem::path back_;
};

class CardPtr : public BaseObjectPtr
{
public:
    enum ShowType{
        BACK,
        FACE,
    };
    CardPtr(std::shared_ptr<Card> card = std::make_shared<Card>(NULL));
    CardPtr Create(bool visible = false);
    static void DeclarationToLua(sol::table& namespace_);
    boost::filesystem::path GetFace();
    boost::filesystem::path GetBack();
    void SetFace(const boost::filesystem::path&);
    void SetBack(const boost::filesystem::path&);
    void Show(ShowType val = BACK);
    friend class CardHolderPtr;
private:
    std::shared_ptr<Card> card_;
};

#endif // CARD_H
