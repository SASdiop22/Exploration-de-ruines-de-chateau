#include "acteur.h"
 #include <random>

aventurier::aventurier(double  vie, double force,double bourse, double stabiliteEpee, double stabiliteArmure ):d_pvie{vie}, d_pforce{force},
d_bourse{bourse}, d_Epee{stabiliteEpee}, d_Armure{stabiliteArmure}
{}

double aventurier:: point_vie() const
{ return d_pvie;
}
double aventurier::point_force() const
{
    return d_pforce;
}

double  aventurier:: ForceAttaque()
{  double r {d_pforce+ d_Epee.solidite()};
   double proba = std::rand() % 2;
   if(proba<0.8)
    return r*0.9;
}

void aventurier::EstAttaquee( double force)
{
   d_Armure-= force*(3/4); 
   d_pvie-= d_pvie*(1/4);
}
/** deplacement d'un aventurier on a dit �a � gerer dans l'interface */
void aventurier::SeDeplace()
{}
double monstre::habilite() const
{

}

void monstreVoyant:: SeDeplace()
{

}


