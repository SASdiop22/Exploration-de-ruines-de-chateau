#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED

class point{
public:
    point(double x, double y);
    double x()const;
    double y() const;
private:
    double d_x, d_y;
};


#endif // POINT_H_INCLUDED
