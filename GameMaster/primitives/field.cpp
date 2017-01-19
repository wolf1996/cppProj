#include "field.h"

Field::Field()
{

}

std::shared_ptr<Chip> Field::GetChip(const std::string& username){
    auto result =std::shared_ptr<Chip>(new Chip);
    chips_[username]  = result;
    return result;
}
