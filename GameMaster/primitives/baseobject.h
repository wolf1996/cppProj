#ifndef BASEOBJECT_H
#define BASEOBJECT_H

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
    virtual bool isVisible(void){
        return this->visible_;
    }
protected:
    bool visible_;
};

#endif // BASEOBJECT_H
