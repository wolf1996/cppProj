#include "field.h"

Field::Field(): BaseObject()
{

}

Field::Field(bool visible): BaseObject(visible)
{

}

std::shared_ptr<Chip> Field::GetChip(const std::string& username){
    auto result =std::shared_ptr<Chip>(new Chip);
    chips_[username]  = result;
    return result;
}

void Field::DeclarationToLua(sol::table &namespace_)
{
    sol::constructors<sol::types<>,sol::types<bool>> ctor;
    namespace_.new_usertype<Field>("Field",
                                        ctor,
                                        "isVisible",&Field::isVisible,
                                        "GetChip",&Field::GetChip
                                        );
}
