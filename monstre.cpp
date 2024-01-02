#include "monstre.h"
#include "aventurier.h"
#include <chrono>  // Pour utiliser std::chrono
#include <thread>

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
    const monstreAveugle* aveugle = dynamic_cast<const monstreAveugle*>(this);
        if (aveugle) {
            return 'A';
        }

        const monstreVoyant* voyant = dynamic_cast<const monstreVoyant*>(this);
        if (voyant) {
            return 'V';
        }
}



void monstre:: attaque(std::unique_ptr<aventurier>& A)
{
    double f{ monstre::ForceDAttaque()};
   //aventurier perd (1/4)*f de ses points de vie
   // aventurier* aventurierCible = static_cast<aventurier*>(&act);
      double PVieAventurier= A->pointDevie();
       PVieAventurier-= f/4;
       A->ChangePointDeVie(PVieAventurier);
       //Armure perd 3/4*f de ses points de solidites
        double p = (f*3)/8;
        A->PerteDePointArmure(p);

}
