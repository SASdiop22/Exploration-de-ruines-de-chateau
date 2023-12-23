#ifndef ACTEUR_H_INCLUDED
#define ACTEUR_H_INCLUDED

#include<iostream>
#include <ostream>
#include "armes.h"
#include "point.h"
#include <memory>

#include "armes.h"


class acteur
{
public:
    virtual ~acteur()= default;
    acteur(double pointVie, double pointForce, point position );
     double pointDevie()const;
     void ChangePointDeVie(double pVie) ;
     void ChangePointDeForce(double pForce);
     double pointDeforce()const;
    bool estMort() const;
    virtual double ForceDAttaque() const =0;
    virtual void attaque(acteur& act)=0;
    virtual char symbole() const=0;
    point position() const;

private:
    double d_pvie, d_pforce;
    point d_position;
};

#endif // ACTEUR_H_INCLUDED

