#include "monstre.h"
#include "aventurier.h"


monstre::monstre(double pointVie,double pointForce,point position, double habilite ): acteur{pointVie, pointForce, position},
 d_habilite{habilite}
{}

double monstre::habilite() const
{
   return d_habilite;
}


double  monstre::ForceDAttaque() const
{
    return pointDeforce()*0.9* d_habilite;

}


char monstre::symbole() const
{
      return 'M';
}



void monstre:: attaque(acteur& act)
{
    double f{ monstre::ForceDAttaque()};
   //aventurier perd (1/4)*f de ses points de vie
    aventurier* aventurierCible = static_cast<aventurier*>(&act);
      double PVieAventurier= aventurierCible->pointDevie();
       PVieAventurier-= f/4;
       aventurierCible->ChangePointDeVie(PVieAventurier);
       //Armure perd 3/4*f de ses points de solidites

        double p = (f*3)/8;
        aventurierCible->PerteDePointArmure(p);

}
