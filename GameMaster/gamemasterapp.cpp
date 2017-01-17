#include "gamemasterapp.h"

GameMasterApp::GameMasterApp():config_(NULL)
{
}

void GameMasterApp::OpenConfig(const std::string &filename){
    config_ = std::shared_ptr<ConfigFile>(ConfigFile::GetConfig(filename));
    std::cout<<"var file is"<<config_->GetVarFileName()<<std::endl;
    std::cout<<"code file is"<<config_->GetCodeFileName()<<std::endl;
}
