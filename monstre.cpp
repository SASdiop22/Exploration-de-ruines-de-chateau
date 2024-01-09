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


char monstreVoyant::symbole() const
{
      return 'M';
}
char monstreAveugle::symbole() const
{
      return 'm';
}



void monstre:: attaque(std::unique_ptr<aventurier>& A)
{
    double f{ monstre::ForceDAttaque()};
   //aventurier perd (1/4)*f de ses points de vie
   // aventurier* aventurierCible = static_cast<aventurier*>(&act);
    monstre::ChangePointDeForce(pointDeforce()-f);
      double PVieAventurier= A->pointDevie();
       PVieAventurier-= f/4;
       A->ChangePointDeVie(PVieAventurier);
       //Armure perd 3/4*f de ses points de solidites
        double p = (f*3)/8;
        A->PerteDePointArmure(p);

}
