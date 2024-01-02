#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
#include <memory>
#include <vector>
#include "acteur.h"
#include "monstre.h"
#include "aventurier.h"
#include "deplacement.h"
#include "Terrain.h"
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
    void  deplaceMonstreVoyant(  std::unique_ptr<acteur> & M);
    /** calcul de distance */
     int distanceEntreMonstre_Aventurier(std::unique_ptr<acteur>& M) const;
     /** fonction pour  verifier qu' une case de terrain est accessible ou pas */
     bool CaseAccessible(int x, int y) const;

private:
    std::unique_ptr<aventurier> d_aventurier;
    std::vector<std::unique_ptr<monstre>> d_monstres;
    terrain d_terrain;

};


#endif // GAME_H_INCLUDED
