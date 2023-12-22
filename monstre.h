#ifndef MONSTRE_H_INCLUDED
#define MONSTRE_H_INCLUDED

#include <memory>
#include "point.h"
#include "acteur.h"
#include "aventurier.h"

class monstre:public acteur
{
public:
    monstre(double pointVie,double pointForce, point position,  double habilite );
    double habilite() const ;
    double  ForceDAttaque() const override;
    void  attaque(aventurier& A);
    char symbole() const override;
private:
    double d_habilite;

};

class monstreVoyant:public monstre
{
    public:
 //    void SeDeplace() override;

};
class monstreAveugle: public monstre
{
    public:
   // void SeDeplace() override;
};



#endif // MONSTRE_H_INCLUDED
