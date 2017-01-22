#include "messagebox.h"


MessageBox::MessageBox()
{

}

void MessageBox::DeclarationToLua(sol::table &namespace_)
{
    sol::constructors<sol::types<>> ctor;
    namespace_.new_usertype<MessageBox>("MessageBox",
                                       ctor,
                                       "isVisible",&MessageBox::isVisible
                                       );
}

MessageBoxPtr::MessageBoxPtr(std::shared_ptr<MessageBox> m_box)
{
    this->message_box_ = m_box;
}

MessageBoxPtr MessageBoxPtr::Create()
{
    if(this->message_box_)
        return *this;
    this->message_box_ = std::make_shared<MessageBox>(MessageBox());
    return *this;
}

void MessageBoxPtr::DeclarationToLua(sol::table &namespace_)
{
    namespace_.new_usertype<MessageBoxPtr>("MessageBoxPtr",
                                           "isVisible",&MessageBoxPtr::isVisible,
                                           "Create",&MessageBoxPtr::Create
                                           );
}
