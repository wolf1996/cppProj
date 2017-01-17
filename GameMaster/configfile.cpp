#include "configfile.h"
#include "configfilelua.h"
ConfigFile* ConfigFile::GetConfig(const std::string& filename){
    ConfigFile* config = new ConfigFileLua();
    config->Open(filename);
    return config;
}
