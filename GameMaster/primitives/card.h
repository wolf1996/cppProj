#ifndef CARD_H
#define CARD_H

#include "boost/filesystem/path.hpp"

class Card
{
public:
    Card();
private:
    boost::filesystem::path face;
    boost::filesystem::path back;
};

#endif // CARD_H
