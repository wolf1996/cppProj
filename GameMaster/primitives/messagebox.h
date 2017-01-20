#ifndef MESSAGEBOX_H
#define MESSAGEBOX_H

#include <sol.hpp>
#include <string>
#include "baseobject.h"
class MessageBox : public BaseObject
{
public:
    MessageBox();
<<<<<<< HEAD
    MessageBox(bool visible);
    static void DeclarationToLua(sol::table& namespace_);
    void SetText(const std::string& );//add
    std::string GetText();//add
    void Show();//add
private:
    std::string text_;
=======

>>>>>>> b79a61625964c49fc8eac9d4779260e71ff73d14
};

#endif // MESSAGEBOX_H
