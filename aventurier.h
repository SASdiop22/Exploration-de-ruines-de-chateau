#ifndef AVENTURIER_H_INCLUDED
#define AVENTURIER_H_INCLUDED
#include "acteur.h"

class acteur;
class aventurier : public acteur
{
public:
    aventurier(double vie, double force, point position, double stabiliteEpee, double stabiliteArmure );

    double ForceDAttaque() const override;
    void Quand_Aventurier_Tue_Monstre (acteur& Monstre);
/** quant le monstre attaque l'aventurier l'armure perd des points donc j'ai besoin de cette methode
pour acceder au donnees de l'armure dans la methode monstre::attaque()*/
   void  PerteDePointArmure(double point) ;
     void attaque(acteur& act) override;
    char symbole() const override;
private:
     armes d_Epee;
     armes d_Armure;
};

#endif // AVENTURIER_H_INCLUDED
