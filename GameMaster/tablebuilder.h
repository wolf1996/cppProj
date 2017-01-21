#ifndef TABLEBUILDER_H
#define TABLEBUILDER_H

#include "sol.hpp"
#include "objectmanager.h"

class TableBuilder{
public:
    TableBuilder(sol::state& lua);
    ~TableBuilder(){}
   void Fill(ObjectManager &man);
private:
    sol::state& lua_;
};

#endif // TABLEBUILDER_H
