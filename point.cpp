#include "point.h"
#include <string>
#include <math.h>

using namespace std;
point::point(double x, double y) : d_x{x} , d_y{y}
{
}
point::point() : d_x{0}, d_y{0}
{
}
double point::x() const
{
    return d_x;
}
double point::y() const
{
    return d_y;
}
double point::distance(point &p)
{
    double x = abs(p.x() - d_x);
    double y = abs(p.y() - d_y);
    double dist = sqrt(x*x + y*y);
    return dist;
}
void point::deplaceEn(double dx, double dy)
{
    d_x = dx;
    d_y = dy;
}
void point::deplaceDe(double dx, double dy)
{
    d_x += dx;
    d_y += dy;
}
