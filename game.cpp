#include "game.h"
game::game(): d_aventurier{}, d_monstres{}, d_terrain{}
{
}
terrain game::terrainGame() const
{
    return d_terrain;
}

void game::ajoute(std::unique_ptr<aventurier> A)
{
    d_aventurier = std::move(A);
}


void game::ajoute(std::unique_ptr<monstre> M)
{
    d_monstres.push_back(std::move(M));
}

void game::ajoute(terrain T)
{
    d_terrain = T;
}
void game::remplirTerrain()
{
    d_terrain.attribuerMurTerrain();
    d_terrain.initialiserActeur(d_aventurier,d_monstres);
}


void game::combat(std::unique_ptr<aventurier>& A, std::unique_ptr<monstre>& M)
{
    while(bool tour = true)
    {
        M->attaque(A);
        if(A->estMort())
        {
            tour = false;
        }
        else
        {
            A->attaque(M);
            if(M->estMort())
            {
                int i {0};
                while(i < d_monstres.size() && d_monstres[i] != M)
                {
                    i++;
                }
                d_monstres.erase(d_monstres.begin()+i);
                tour = false;
            }
        }
    }
}


