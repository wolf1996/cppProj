#include "gamemasterapp.h"

GameMasterApp::GameMasterApp():config_(NULL)
{
}

void GameMasterApp::LoadConfig(const std::string &filename){
    config_ = std::shared_ptr<ConfigFile>(ConfigFile::GetConfig(filename));
    std::cout<<"var file is"<<config_->GetVarFileName()<<std::endl;
    std::cout<<"code file is"<<config_->GetCodeFileName()<<std::endl;
    object_manager_.LoadVariables(config_);
    script_manager_.ApplyConfig(config_);
    std::string var = object_manager_.GetTest(std::string("blah")).GetTest(std::string("bluh"));
    std::cout<<"test is "<< var<< std::endl;
}
