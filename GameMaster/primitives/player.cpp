#include "player.h"

Player::Player()
{

}
const char* Player::GetTest(const std::string& name){
    std::cout<< "call player_test with value: " << name << std::endl;
    std::string var = name;
   return "var";
}
