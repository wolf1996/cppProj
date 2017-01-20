#ifndef MESSAGEBOX_H
#define MESSAGEBOX_H

#include <sol.hpp>
#include <string>
#include "baseobject.h"
class MessageBox : public BaseObject
{
public:
    MessageBox();
    MessageBox(bool visible);
    static void DeclarationToLua(sol::table& namespace_);
    void SetText(const std::string& );//add
    std::string GetText();//add
    void Show();//add
private:
    std::string text_;
};

#endif // MESSAGEBOX_H
