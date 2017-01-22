#include "infoboard.h"

InfoBoard::InfoBoard(): BaseObject()
{

}

InfoBoard::InfoBoard(bool visible): BaseObject(visible)
{

}

void InfoBoard::DeclarationToLua(sol::table &namespace_)
{
    sol::constructors<sol::types<>,sol::types<bool>> ctor;
    namespace_.new_usertype<InfoBoard>("Infoboard",
                                       ctor,
                                       "isVisible",&InfoBoard::isVisible,
                                       "Text",sol::property(&InfoBoard::GetText,&InfoBoard::SetText),
                                       "Show",&InfoBoard::Show
                                       );
}


void InfoBoard::SetText(const std::string& text){
    text_ = text;
}

std::string InfoBoard::GetText(){
    return text_;
}

void InfoBoard::Show(){

}

InfoBoardPtr::InfoBoardPtr(std::shared_ptr<InfoBoard> info_board) : BaseObjectPtr(info_board)
{
    this->info_board_ = info_board;
}

InfoBoardPtr InfoBoardPtr::Create(bool visible)
{
    if(this->info_board_)
        return *this;
    this->info_board_ = std::make_shared<InfoBoard>(InfoBoard(visible));
    return *this;
}

void InfoBoardPtr::DeclarationToLua(sol::table &namespace_)
{
    namespace_.new_usertype<InfoBoardPtr>("InfoboardPtr",
                                          "Create",&InfoBoardPtr::Create,
                                          "isVisible",&InfoBoardPtr::isVisible,
                                          "Text",sol::property(&InfoBoardPtr::GetText,&InfoBoardPtr::SetText),
                                          "Show",&InfoBoardPtr::Show
                                          );
}

void InfoBoardPtr::SetText(const std::__cxx11::string &text)
{
    this->info_board_->SetText(text);
}

std::__cxx11::string InfoBoardPtr::GetText()
{
    return this->info_board_->GetText();
}

void InfoBoardPtr::Show()
{
    this->info_board_->Show();
}
