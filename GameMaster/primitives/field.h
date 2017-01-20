#ifndef FIELD_H
#define FIELD_H

#include <vector>
#include <memory>
#include <map>

#include "chip.h"

class Field
{
public:
    Field();
    std::shared_ptr<Chip> GetChip(const std::string&);
    void Show();
private:
    std::map<std::string,std::shared_ptr<Chip> > chips_;
};

#endif // FIELD_H
