#include "baseobject.h"

sol::table BaseObject::GetProperty(){
    return props_;
}

void BaseObject::SetProperty(sol::table props){
    props_ = props;
}
