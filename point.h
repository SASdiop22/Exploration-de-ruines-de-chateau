#ifndef POINTS_H_INCLUDED
#define POINTS_H_INCLUDED
#include <iostream>
class transfoAffine;
using namespace std;
class point  {
public:
    point(double x, double y);
    point(); ///Constructeur par defaut
    double x() const;
    double y() const;
    double distance(point &p);
    void deplaceEn(double dx, double dy);
    void deplaceDe(double dx, double dy);

private:
    double d_x, d_y;
};
bool operator==(const point& p1, const point& p2);
bool operator!=(const point& p1, const point& p2);
#endif // POINTS_H_INCLUDED
