#include "messagebox.h"

MessageBox::MessageBox()
{

}
void MessageBox::SetText(const std::string& text){
    text_ = text;
}

std::string MessageBox::GetText(){
    return text_;
}

void MessageBox::Show(){

}
