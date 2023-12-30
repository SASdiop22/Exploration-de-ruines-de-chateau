#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
#include <memory>
#include <vector>
#include "acteur.h"
#include "monstre.h"
#include "aventurier.h"
#include "Terrain.h"
#include"deplacement.h"
class game
{
public:
    game();
    terrain terrainGame() const;
    void ajoute(std::unique_ptr<aventurier> A);
    void ajoute(std::unique_ptr<monstre> M);
    void ajoute(terrain T);
    void remplirTerrain();
    void combat(std::unique_ptr<aventurier>& A, std::unique_ptr<monstre>& M);
    void deplaceAventurier(std::unique_ptr<aventurier> & A);
    void deplaceMonstreAveugle(std::unique_ptr<acteur> & M, deplacement& d);
private:
    std::unique_ptr<aventurier> d_aventurier;
    std::vector<std::unique_ptr<monstre>> d_monstres;
    terrain d_terrain;
};


#endif // GAME_H_INCLUDED
