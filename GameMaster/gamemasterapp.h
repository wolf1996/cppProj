#ifndef GAMEMASTERAPP_H
#define GAMEMASTERAPP_H

#include <string>

class GameMasterApp{
    std::string config_file_name_;
public:
    GameMasterApp();
    void LoadConfigFile(const std::string& config_file_name);
};

#endif // GAMEMASTERAPP_H
