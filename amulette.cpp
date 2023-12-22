#include"amulette.h"
#include"point.h"

amulette::amulette(const point& p):
    d_position{p}
{}

point amulette::position_amulette() const{
    return d_position;
}
char amulette::symbole() const{
    return 'a';
}
