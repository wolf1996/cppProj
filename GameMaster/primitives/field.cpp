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
                                        "isVisible",&Field::isVisible
                                        );
}

void Field::Show()
{


}

FieldPtr::FieldPtr(std::shared_ptr<Field> field): BaseObjectPtr(field)
{
    this->field_ = field;
}

FieldPtr FieldPtr::Create(bool visible)
{
    if(this->field_)
        return *this;
    this->field_ = std::make_shared<Field>(Field(visible));
    return *this;
}

ChipPtr FieldPtr::GetChip(const std::__cxx11::string &username)
{
    auto result = (this->field_->GetChip(username));
    return ChipPtr(result);
}

void FieldPtr::DeclarationToLua(sol::table &namespace_)
{
    namespace_.new_usertype<FieldPtr>("FieldPtr",
                                      "Create",&FieldPtr::Create,
                                      "isVisible",&FieldPtr::isVisible,
                                      "Show",&FieldPtr::Show,
                                      "GetChip",&FieldPtr::GetChip
                                      );
}

void FieldPtr::Show()
{
    this->field_->Show();
}

Field &FieldPtr::operator*()
{
    return *(this->field_);
}
