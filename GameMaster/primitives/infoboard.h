#ifndef INFOBOARD_H
#define INFOBOARD_H
#include "baseobject.h"

class InfoBoard: public BaseObject
{
public:
    InfoBoard();
    InfoBoard(bool visible);
    static void DeclarationToLua(sol::table& namespace_);
    void SetText(const std::string& );//add
    std::string GetText();//add
    void Show();//add
private:
    std::string text_;
};

#endif // INFOBOARD_H
