#ifndef MONSTRE_H_INCLUDED
#define MONSTRE_H_INCLUDED
#include "point.h"
#include "acteur.h"
#include "deplacement.h"
#include "aventurier.h"
#include <memory>
class aventurier;
class monstre:public acteur
{
public:
    monstre(double pointVie = 100,double pointForce = 500, point position = point(1.0,0.0),  double habilite= 0.5);
    double habilite() const ;
    double  ForceDAttaque() const override;
    void  attaque(std::unique_ptr<aventurier>& A);
    /** j'ai  changer le symbole entre les deux monstres */
     char symbole() const override;
private:
    double d_habilite;

};

class monstreVoyant:public monstre
{
    public:


};
class monstreAveugle: public monstre
{
    public:

};



#endif // MONSTRE_H_INCLUDED
