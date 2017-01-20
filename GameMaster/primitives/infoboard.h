#ifndef INFOBOARD_H
#define INFOBOARD_H
#include "baseobject.h"

class InfoBoard: public BaseObject
{
public:
    InfoBoard();
    InfoBoard(bool visible);
    static void DeclarationToLua(sol::table& namespace_);
};

#endif // INFOBOARD_H
