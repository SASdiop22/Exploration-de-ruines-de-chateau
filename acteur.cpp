#include "acteur.h"
 #include <random>

/***********************************   AVENTURIER    *************/

aventurier::aventurier(double  vie, double force,double bourse, double stabiliteEpee, double stabiliteArmure ): d_pvie{vie}, d_pforce{force},
d_bourse{bourse}, d_Epee{stabiliteEpee}, d_Armure{stabiliteArmure}
{}

double aventurier:: point_vie() const
{ return d_pvie;
}

void aventurier::PointVie(double pVie)
{
    d_pvie= pVie;
}

double aventurier::point_force() const
{
    return d_pforce;
}

double aventurier::bourse() const
{
    return d_bourse;
}

double  aventurier:: Attaque_Avec_Force()
{  double r {d_pforce+ d_Epee.solidite()};
   double proba = std::rand() % 2;
   if(proba<0.8)
    return r*0.9;
}

void aventurier::Tue_Monstre(acteur& Monstre)
{
    d_pforce += Monstre.point_force()/4;
    d_pvie+=(Monstre.point_force()*3)/4;
}
bool aventurier::estMort() const
{
     return d_pvie == 0.0;

}

double aventurier::x() const
{
  return d_x;
}

double aventurier::y() const
{  return d_y;
}

void  aventurier::x (double x)
{
    d_x = x;
}
void  aventurier::y(double y)
{
    d_y= y;
}
void aventurier::symboleActeur() const
{
        std::cout << "A";
}

 double aventurier::SoliditeEpee() const
 {
     return d_Epee.solidite();
 }

    void aventurier::pSoliditeEpee(double p)
    {
        d_Epee.Pointsolidite(p);
    }
//void aventurier::EstAttaque( double force)
//{
//   d_Armure.pointsSoldite()-= force*(3/8);
//   d_pvie-= d_pvie*(1/4);
//}

void  aventurier::attaque(acteur& act)
{
    double f= this->Attaque_Avec_Force();
    double point = d_Epee.solidite();
    point --;
    d_Epee.Pointsolidite(point);

    double p= act.point_vie();
    p-= f;
    act.PointVie(p);
}



/** deplacement d'un aventurier on a dit �a � gerer dans l'interface */
//void aventurier::SeDeplace()
//{
//}


/************************** MONSTRE *****************************/


monstre::monstre(double pointVie,double pointForce, double habilite ): d_pvie {pointVie}, d_pforce{pointForce}, d_habilite{habilite}
{}

double monstre::habilite() const
{
   return d_habilite;
}

 double monstre:: point_vie() const
 {
     return d_pvie;
 }

 void monstre::PointVie(double pVie)
 {
     d_pvie= pVie;
 }

double monstre::point_force() const
{
    return d_pforce;
}

double  monstre::Attaque_Avec_Force()
{
    return d_pforce*0.9* d_habilite;

}
 bool  monstre::estMort() const
 {
     return d_pvie == 0.0;
 }

//void monstre::attaque(acteur& act)
//{
//  double f= this->Attaque_Avec_Force();
//  double ps=
//}
void monstre::attaque(aventurier& a)
{     double f= this->Attaque_Avec_Force();
       double p= a.SoliditeEpee();
       p-=(f*3)/8;
        a.pSoliditeEpee(p);
        double r= a.point_vie();
        r-= f/4;
        a.PointVie(r);
}


 double monstre::x() const
 {
     return d_x;
 }
 double monstre::y() const
 {
     return d_y;
 }
void monstre::x (double x)
{
      d_x= x;
}
void monstre::y(double y)
{
    d_y= y;
}
void monstre::symboleActeur() const
{
      std::cout << "M";
}
