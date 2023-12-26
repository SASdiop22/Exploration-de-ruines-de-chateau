#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
#include <memory>
#include <vector>
#include "acteur.h"
#include "monstre.h"
#include "aventurier.h"
#include "Terrain.h"
class game
{
public:
    game();
    void ajoute(std::unique_ptr<aventurier> A);
    void ajoute(std::unique_ptr<monstre> M);
    void remplirTerrain(int l, int h);
    void combat();
    void deplaceAventurier(std::unique_ptr<aventurier> & A);
private:
    std::unique_ptr<aventurier> d_aventurier;
    std::vector<std::unique_ptr<monstre>> d_monstres;
    terrain d_terrain;
};


#endif // GAME_H_INCLUDED
