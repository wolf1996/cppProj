#ifndef BASEOBJECT_H
#define BASEOBJECT_H
extern "C" {
    # include "lua.h"
    # include "lauxlib.h"
    # include "lualib.h"
}
#include <LuaBridge.h>


class BaseObject
{
public:
    BaseObject();
    virtual ~BaseObject() = 0;
    static void DeclarationToLua(lua_State* L){}
    virtual bool isVisible(void){
        return false;
    }
};

#endif // BASEOBJECT_H
