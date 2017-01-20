#ifndef MESSAGEBOX_H
#define MESSAGEBOX_H

#include <sol.hpp>
#include <string>
///// наследование от baseobject??????
class MessageBox
{
public:
    MessageBox();

    static void DeclarationToLua(sol::table& namespace_);
    void SetText(const std::string& );//add
    std::string GetText();//add
    void Show();//add
private:
    std::string text_;
};

#endif // MESSAGEBOX_H
