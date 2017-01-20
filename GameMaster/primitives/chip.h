#ifndef CHIP_H
#define CHIP_H

#include <string>
#include <memory>


class Chip
{
public:
    Chip();
    void MoveForward(int num = 1);
    void SetPosition(unsigned int num);
    unsigned int GetPosition();
private:
    unsigned int position_;
};

#endif // CHIP_H
