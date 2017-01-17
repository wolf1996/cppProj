#ifndef CONFIGFILE_H
#define CONFIGFILE_H
#include <string>


//ConfigFile base class to other config files
//  will be fabric method hear

class ConfigFile
{
    ConfigFile(){

    }
public:
    virtual ~ConfigFile(){
    }
    virtual void OpenFile();
    virtual std::string GetVarFileName() = 0;
    virtual std::string GetCodeFileName() = 0;
    static ConfigFile* GetConfig(const std::string& filename);
};

#endif // CONFIGFILE_H
