#ifndef AMULETTE_H_INCLUDED
#define AMULETTE_H_INCLUDED
#include <iostream>
#include"point.h"

class amulette{
public:
    amulette(const point& p);
    point position_amulette() const;
    char symbole() const;
private:
    point d_position;
};



#endif // AMULETTE_H_INCLUDED
