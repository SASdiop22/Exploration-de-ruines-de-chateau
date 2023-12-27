#ifndef AVENTURIER_H_INCLUDED
#define AVENTURIER_H_INCLUDED
#include "acteur.h"
#include "monstre.h"
#include <memory>
class acteur;
class monstre;
class aventurier : public acteur
{
public:
    aventurier(double vie = 200, double force = 1000, point position = point(1,0), double stabiliteEpee = 100, double stabiliteArmure = 300 );

    double ForceDAttaque() const override;
    void Quand_Aventurier_Tue_Monstre (acteur& Monstre);
/** quant le monstre attaque l'aventurier l'armure perd des points donc j'ai besoin de cette methode
pour acceder au donnees de l'armure dans la methode monstre::attaque()*/
   void  PerteDePointArmure(double point) ;
     void attaque(std::unique_ptr<monstre>& M);
    char symbole() const override;
private:
     armes d_Epee;
     armes d_Armure;
};

#endif // AVENTURIER_H_INCLUDED
