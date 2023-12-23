#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED

class point{
public:
    point(int x, int y);
    int x() const;
    int y() const;
    void setx(int x);
    void sety(int y);
friend bool operator==(const point& p1,const point& p2);
private:
    int d_x;
    int d_y;
};


#endif // POINT_H_INCLUDED
