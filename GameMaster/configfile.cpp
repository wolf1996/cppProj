#include "configfile.h"
#include "configfilelua.h"
//TODO add filecheck system
ConfigFile* ConfigFile::GetConfig(const std::string& filename){
    ConfigFile* config = new ConfigFileLua();
    config->Load(filename);
    return config;
}
