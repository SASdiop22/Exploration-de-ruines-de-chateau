#ifndef TERRAIN_H_INCLUDED
#define TERRAIN_H_INCLUDED
#include<vector>
#include"aventurier.h"
#include"monstre.h"

#include<memory>
class terrain
{

public:
    terrain(int largeur= 15,int hauteur= 15);
    int largeur() const;
    int hauteur() const;
    std::vector<std::vector<char>> tableau() const;
    void attribuerMurTerrain() ;
    void initialiserActeur(std::unique_ptr<aventurier>& aventurier,std::vector<std::unique_ptr<monstre>>& monstres);
  /** j'ai ajoute celle la*/
   bool estCaseAccessible(int ligne, int colonne) const;

private:
    std::vector<std::vector<char>>d_tableau;

};

#endif // TERRAIN_H_INCLUDED
