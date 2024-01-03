#ifndef TERRAIN_H_INCLUDED
#define TERRAIN_H_INCLUDED
#include<vector>
#include"aventurier.h"
#include"monstre.h"
class terrain
{

public:
    terrain();
    terrain(int largeur,int hauteur);
    int largeur() const;
    int hauteur() const;
    std::vector<std::vector<char>> tableau() const;
    void attribuerMurTerrain() ;
    void initialiserActeur(aventurier& aventurier,std::vector<std::unique_ptr<monstre>>& monstres);


private:
    std::vector<std::vector<char>>d_tableau;

};

#endif // TERRAIN_H_INCLUDED
