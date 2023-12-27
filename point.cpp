#include "point.h"
#include <string>
#include <math.h>

using namespace std;
point::point(int x, int y) : d_x{x} , d_y{y}
{
}
point::point() : d_x{0}, d_y{0}
{
}
int point::x() const
{
    return d_x;
}
int point::y() const
{
    return d_y;
}
double point::distance(point &p)
{
    int x = abs(p.x() - d_x);
    int y = abs(p.y() - d_y);
    double dist = sqrt(x*x + y*y);
    return dist;
}
void point::deplaceEn(int dx, int dy)
{
    d_x = dx;
    d_y = dy;
}
void point::deplaceDe(int dx, int dy)
{
    d_x += dx;
    d_y += dy;
}
