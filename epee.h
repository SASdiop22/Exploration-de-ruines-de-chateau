#ifndef EPEE_H_INCLUDED
#define EPEE_H_INCLUDED
#include"armes.h"

class epee : public armes{
public:
    epee(double pointSolidite);
    void utiliser()const override;
    void recupererPoint(int point) const override;
private:
    double d_pointsSoldite;
} ;

#endif // EPEE_H_INCLUDED
