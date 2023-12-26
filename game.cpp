#include "game.h"
game::game(): d_aventurier{}, d_monstres{}, d_terrain{}
{
}


void game::ajoute(std::unique_ptr<aventurier> A)
{
    d_aventurier = std::move(A);
}


void game::ajoute(std::unique_ptr<monstre> M)
{
    d_monstres.push_back(std::move(M));
}


void game::remplirTerrain(int l, int h)
{
    d_terrain = terrain(l,h);
    d_terrain.attribuerMurTerrain();
    d_terrain.initialiserActeur(d_aventurier,d_monstres);
}


void game::combat()
{
    //if(d_monstres[0]->position() == d_aventurier->position())
    //{
        while(bool tour = true)
        {
            d_monstres[0]->attaque(d_aventurier);
            if(d_aventurier->estMort())
            {
                tour = false;
            }
            else
            {
                d_aventurier->attaque(d_monstres[0]);
                if(d_monstres[0]->estMort())
                    d_monstres
                    tour = false;
            }
        }
    //}
}

void game::deplaceAventurier(string choix)
{
    deplacement d{};
    switch choix:
    case "R":
        d.deplaceR(d_aventurier);
    case "L":
        d

}
