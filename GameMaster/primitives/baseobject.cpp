#include "baseobject.h"

sol::table BaseObject::GetProperty(){
    return props_;
}

void BaseObject::SetProperty(sol::table props){
    props_ = props;
}

BaseObjectPtr::BaseObjectPtr(std::shared_ptr<BaseObject> b_obj)
{
    this->b_obj = b_obj;
}
