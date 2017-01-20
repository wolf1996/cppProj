#ifndef CHIP_H
#define CHIP_H

#include <string>
#include <memory>
#include "baseobject.h"

class Chip : public BaseObject
{
public:
    Chip();
    Chip(bool visible);
    void MoveForward(int num = 1);
    void SetPosition(unsigned int num);
    unsigned int GetPosition();
    static void DeclarationToLua(sol::table& namespace_);
private:
    unsigned int position_;
};

#endif // CHIP_H
