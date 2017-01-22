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

class InfoBoardPtr : public BaseObjectPtr
{
public:
    InfoBoardPtr(std::shared_ptr<InfoBoard> info_board = std::make_shared<InfoBoard>(NULL));
    InfoBoardPtr Create(bool visible = false);
    static void DeclarationToLua(sol::table& namespace_);
    void SetText(const std::string& text);//add
    std::string GetText();//add
    void Show();//add
private:
    std::shared_ptr<InfoBoard> info_board_;
};

#endif // INFOBOARD_H
