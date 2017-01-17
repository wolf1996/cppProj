#include "configfilelua.h"

ConfigFileLua::ConfigFileLua()
{

}


void ConfigFileLua::Load(const std::string & filename){

}

std::string ConfigFileLua::GetCodeFileName(){
    return std::string("codefile.lua");
}

std::string ConfigFileLua::GetVarFileName(){
    return std::string("varfile.lua");
}
