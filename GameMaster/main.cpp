// main.cpp
//
// TODO: base object
#include <iostream>
#include <LuaBridge.h>

#include "gamemasterapp.h"

extern "C" {
    # include "lua.h"
    # include "lauxlib.h"
    # include "lualib.h"
}

void printMessage_const(const std::string& s) {
    std::cout << s << std::endl;
}

void printMessage(std::string& s) {
    std::cout << s << std::endl;
}

//using namespace luabridge;
int main() {
    std::string config_file_name("WWWWWWWWWWWWWWWWWWWWWWW");
    GameMasterApp  app;
    app.LoadConfig(config_file_name);


    luabridge::lua_State* L = luabridge::luaL_newstate();
        luabridge::luaL_openlibs(L);

        luabridge::getGlobalNamespace(L)
                .addFunction("printMessage_const", printMessage_const)
                .addFunction("printMessage", printMessage)
                    .beginClass<Player> ("Player")
                        .addConstructor<void(*)()>()
                        .addFunction("GetTest",&Player::GetTest)
                    .endClass()
                    .beginClass<ObjectManager> ("ObjectManager")
                        .addConstructor<void(*)()>()
                        .addFunction("GetTest",&ObjectManager::GetTest)
                    .endClass();

        luaL_dofile(L, "../script.lua");
        lua_pcall(L, 0, 0, 0);
        luabridge::LuaRef sumNumbers = getGlobal(L, "sumNumbers");
        luabridge::LuaRef P = getGlobal(L,"P");
        int result = sumNumbers(5, 4);
        std::cout << "Result:" << P.cast<Player>().GetTest("bla") << std::endl;
    return 0;
}
