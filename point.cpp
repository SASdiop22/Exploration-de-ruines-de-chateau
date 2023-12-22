#include"point.h"

point::point(double x, double y): d_x{x}, d_y{y}
{}

double point::x()const{
    return d_x;
}

double point::y() const{
    return d_y;
}
