#ifndef MESSAGEBOX_H
#define MESSAGEBOX_H

<<<<<<< HEAD
#include <sol.hpp>
=======
#include <string>
>>>>>>> 7085158836ea40d2741ef870a6a4cd928be0e28f

///// наследование от baseobject??????
class MessageBox
{
public:
    MessageBox();
<<<<<<< HEAD
    static void DeclarationToLua(sol::table& namespace_);
=======
    void SetText(const std::string& );
    std::string GetText();
    void Show();
private:
    std::string text_;
>>>>>>> 7085158836ea40d2741ef870a6a4cd928be0e28f
};

#endif // MESSAGEBOX_H
