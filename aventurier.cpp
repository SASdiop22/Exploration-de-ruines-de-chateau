#include "aventurier.h"

aventurier::aventurier(double  vie, double force, point position, double stabiliteEpee, double stabiliteArmure ): acteur{vie, force, position},
 d_Epee{stabiliteEpee}, d_Armure{stabiliteArmure}, d_aAllumette{false}
{}

bool aventurier::aAllumette() const
{
    return d_aAllumette;
}

void aventurier::prendAllumette()
{
    d_aAllumette = true;
}

double  aventurier:: ForceDAttaque() const
{  double r {pointDeforce()+ d_Epee.points_de_solidite()};
   double proba = std::rand() % 2;
   if(proba<0.8)
    return r*0.9;
    else return r;
}

void aventurier::Quand_Aventurier_Tue_Monstre(acteur& Monstre)
{

    double g1{Monstre.pointDeforce()/4};
    double g2{(Monstre.pointDeforce()*3)/4};
    double pf= aventurier::pointDeforce();
    double pv= aventurier::pointDevie();
    pf+=g1;
    pv+= g2;
    aventurier::ChangePointDeForce(pf);
    aventurier::ChangePointDeVie(pv);
}

void  aventurier::attaque(std::unique_ptr<monstre>& M)
{
    double f= aventurier::ForceDAttaque();
    d_Epee.perte_de_pointSolidite(1);
    double p = M->pointDevie();
    p-=f;
    M->ChangePointDeVie(p);
}

char aventurier::symbole() const
{
    return 'A';
}

void  aventurier::PerteDePointArmure(double point)
{
    d_Armure.perte_de_pointSolidite(point);
}
