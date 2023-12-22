#include"amulette.h"
#include"point.h"

amulette::amulette(const point& p, const char& symbole):
    d_position{0.0, 0.0}, d_symbole{'a'}
{}

point amulette::position_amulette() const{
    return d_position;
}
char amulette::symbole() const{
    return d_symbole;
}
