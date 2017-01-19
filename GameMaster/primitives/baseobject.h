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
    static void DeclarationToLua(luabridge::lua_State* L){};
    virtual bool isVisible(void){
        return false;
    }
};

#endif // BASEOBJECT_H