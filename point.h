#ifndef POINTS_H_INCLUDED
#define POINTS_H_INCLUDED
#include <iostream>
class transfoAffine;
using namespace std;
class point  {
public:
    point(int x, int y);
    point(); ///Constructeur par defaut
    int  x() const;
    int  y() const;
    double distance(point &p);
    void deplaceEn(int dx, int dy);
    void deplaceDe(int dx, int dy);

private:
    double d_x, d_y;
};
#endif // POINTS_H_INCLUDED
