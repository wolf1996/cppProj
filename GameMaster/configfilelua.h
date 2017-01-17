#ifndef CONFIGFILELUA_H
#define CONFIGFILELUA_H

#include <string>
#include "configfile.h"

class ConfigFileLua: public ConfigFile
{
protected:
    void Load(const std::string& );
public:
    ConfigFileLua();
    ~ConfigFileLua(){
    }
    virtual std::string GetVarFileName();
    virtual std::string GetCodeFileName();
};

#endif // CONFIGFILELUA_H
