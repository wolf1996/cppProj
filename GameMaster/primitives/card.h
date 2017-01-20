#ifndef CARD_H
#define CARD_H

#include "boost/filesystem/path.hpp"
#include "baseobject.h"

class Card : public BaseObject
{
public:
    Card();
    Card(bool visible);
    static void DeclarationToLua(sol::table& namespace_);
private:
    boost::filesystem::path face;
    boost::filesystem::path back;
};

#endif // CARD_H
