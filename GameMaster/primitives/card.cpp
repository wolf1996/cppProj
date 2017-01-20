#include "card.h"

Card::Card()
{

}


boost::filesystem::path Card::GetFace(){
    return face_;
}

boost::filesystem::path Card::GetBack(){
    return back_;
}

void Card::SetFace(const boost::filesystem::path& face){
    face_ = face;
}

void Card::SetBack(const boost::filesystem::path& back){
    back_ = back;
}

void Card::Show(ShowType val){

}
