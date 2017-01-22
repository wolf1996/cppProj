#ifndef MESSAGEBOX_H
#define MESSAGEBOX_H

#include <sol.hpp>
#include <string>
#include "baseobject.h"
class MessageBox : public BaseObject
{
public:
    MessageBox();
    static void DeclarationToLua(sol::table& namespace_);
};

class MessageBoxPtr : public BaseObjectPtr
{
public:
    MessageBoxPtr(std::shared_ptr<MessageBox> m_box = std::make_shared<MessageBox>(NULL));
    MessageBoxPtr Create();
    static void DeclarationToLua(sol::table& namespace_);
private:
    std::shared_ptr<MessageBox> message_box_;
};

#endif // MESSAGEBOX_H
