#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <memory>
#include <map>

#include "configfile.h"
#include "primitives/all.h"

class Player
{
    std::map<std::string, CardHolder> card_holders_;
    std::map<std::string, Chip> chips_;
public:
    Player();
    std::string& GetTest(const std::string& name);
};

#endif // PLAYER_H
