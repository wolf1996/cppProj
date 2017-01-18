#include "player.h"

Player::Player()
{

}
std::string& Player::GetTest(const std::string& name){
   static std::string var = name;
   return var;
}
