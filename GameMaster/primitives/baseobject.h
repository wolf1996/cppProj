#ifndef BASEOBJECT_H
#define BASEOBJECT_H

#include <string>

#include <sol.hpp>
extern "C" {
    # include "lua.h"
    # include "lauxlib.h"
    # include "lualib.h"
}


class BaseObject
{
public:
    BaseObject(): visible_(false){}
    BaseObject(bool visible): visible_(visible){}
    virtual ~BaseObject(){}
    virtual bool isVisible(void){ //add
        return this->visible_;
    }
    sol::table GetProperty(); //add
    void SetProperty(sol::table); //add
protected:
    bool visible_;
    sol::table props_;
};

class BaseObjectPtr
{
public:
    BaseObjectPtr(std::shared_ptr<BaseObject> b_obj = std::make_shared<BaseObject>(NULL));
    virtual bool isVisible(void)
    {
        return this->b_obj->isVisible();
    }
    sol::table GetProperty(); //add
    void SetProperty(sol::table); //add
protected:
    std::shared_ptr<BaseObject> b_obj;
    sol::table props_;
};
#endif // BASEOBJECT_H
