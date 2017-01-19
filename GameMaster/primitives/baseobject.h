#ifndef BASEOBJECT_H
#define BASEOBJECT_H

#include <LuaBridge.h>

extern "C" {
    # include "lua.h"
    # include "lauxlib.h"
    # include "lualib.h"
}


class BaseObject
{
public:
    BaseObject();
    virtual ~BaseObject(){}
    virtual bool isVisible(void){
        return false;
    }
};

#endif // BASEOBJECT_H
