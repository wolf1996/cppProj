#ifndef FIELD_H
#define FIELD_H

#include <vector>
#include <memory>
#include <map>
#include "baseobject.h"
#include "chip.h"

class Field : public BaseObject
{
public:
    Field();
    Field(bool visible);
    std::shared_ptr<Chip> GetChip(const std::string&);
<<<<<<< HEAD
    static void DeclarationToLua(sol::table& namespace_);
=======
    void Show();
>>>>>>> 7085158836ea40d2741ef870a6a4cd928be0e28f
private:
    std::map<std::string,std::shared_ptr<Chip> > chips_;
};

#endif // FIELD_H
