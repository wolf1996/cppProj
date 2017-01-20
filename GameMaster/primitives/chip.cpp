#include "chip.h"

Chip::Chip():position_(0)
{

}

void Chip::MoveForward(int num){
    position_ += num;
}

void Chip::SetPosition(unsigned int num){
    position_ = num;
}

unsigned int  Chip::GetPosition(){
    return position_;
}
