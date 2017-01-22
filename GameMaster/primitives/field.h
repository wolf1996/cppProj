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
    std::shared_ptr<Chip> GetChip(const std::string&);//add
    static void DeclarationToLua(sol::table& namespace_);
    void Show();//add

private:
    std::map<std::string,std::shared_ptr<Chip> > chips_;

};

class FieldPtr : public BaseObjectPtr
{
public:
    FieldPtr(std::shared_ptr<Field> field = std::make_shared<Field>(NULL));
    FieldPtr Create(bool visible = false);
    ChipPtr GetChip(const std::string&);//add
    static void DeclarationToLua(sol::table& namespace_);
    void Show();//add
    Field& operator* ();
private:
    std::shared_ptr<Field> field_;

};

#endif // FIELD_H
