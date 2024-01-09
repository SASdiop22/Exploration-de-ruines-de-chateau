#ifndef TERRAIN_H_INCLUDED
#define TERRAIN_H_INCLUDED
#include<vector>
#include"aventurier.h"
#include"monstre.h"

#include<memory>
class terrain
{

public:
    terrain(int largeur= 20,int hauteur= 27);
    int largeur() const;
    int hauteur() const;
    std::vector<std::vector<char>> tableau() const;
    void attribuerMurTerrain() ;
    void initialiserActeur(std::unique_ptr<aventurier>& aventurier,std::vector<std::unique_ptr<monstre>>& monstres);
    bool estCaseAccessibleM(int ligne, int colonne) const;
    bool estCaseAccessibleA(int ligne, int colonne) const;
    void effacerActeur(acteur& act);
    void miseAJourActeur(acteur& act);

private:
    std::vector<std::vector<char>>d_tableau;

};

#endif // TERRAIN_H_INCLUDED
