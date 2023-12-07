#ifndef ARMURE_H_INCLUDED
#define ARMURE_H_INCLUDED
#include"armes.h"

class armure : public armes{
public:
    armure(double pointSolidite);
    void utiliser()const override;
    void recupererPoint(int point) const override;
private:
    double pointsSoldite;
};


#endif // ARMURE_H_INCLUDED
