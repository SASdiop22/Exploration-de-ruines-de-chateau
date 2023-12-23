#include "acteur.h"
 #include <random>
acteur::acteur(double pointVie, double pointForce, point position):d_pvie{pointVie}, d_pforce{pointForce}, d_position{position}
{}
double acteur::pointDevie()const
{
    return d_pvie;
}
void acteur::ChangePointDeVie(double pVie)
{
    d_pvie= pVie;
}
void acteur::ChangePointDeForce(double pForce)
{
    d_pforce= pForce;
}
double acteur::pointDeforce()const
{
    return d_pforce;
}

bool acteur::estMort() const
{
    return d_pvie==0.0 ;
}

 point acteur::position() const
 {
     return d_position;

 }
