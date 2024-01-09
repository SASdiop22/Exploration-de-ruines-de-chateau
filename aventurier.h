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
    aventurier(double vie = 200, double force = 1000, point position = point(0,1), double stabiliteEpee = 100, double stabiliteArmure = 300 );
    double ForceDAttaque() const override;
    void Quand_Aventurier_Tue_Monstre (acteur& Monstre);
    void  PerteDePointArmure(double point) ;
    void attaque(std::unique_ptr<monstre>& M);
    bool aAllumette() const;
    void prendAllumette();
    char symbole() const override;
private:
     armes d_Epee;
     armes d_Armure;
     bool d_aAllumette;
};

#endif // AVENTURIER_H_INCLUDED
