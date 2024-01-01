#include"game.h"
#include"point.h"
#include"deplacement.h"

/*game::game(): d_aventurier{nullptr}, d_monstres{}, d_terrain{}
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
}*/

void game::deplaceAventurier(int choix)
{
    deplacement d{};
    switch (choix) {
    case 1 ://se deplacer à droit
        if( d_terrain.tableau()[d_aventurier->position().x()+1][d_aventurier->position().y()] != 'x'
            && d_terrain.tableau()[d_aventurier->position().x()+1][d_aventurier->position().y()] != '#')

            d.deplaceRight(d_aventurier);
        break;
    case 2 ://se deplacer à gauche
        if( d_terrain.tableau()[d_aventurier->position().x()-1][d_aventurier->position().y()] != 'x'
            && d_terrain.tableau()[d_aventurier->position().x()-1][d_aventurier->position().y()] != '#')

            d.deplaceLeft(d_aventurier);
        break;
    case 3 ://se deplacer en haut
         if( d_terrain.tableau()[d_aventurier->position().x()][d_aventurier->position().y()-1] != 'x'
            && d_terrain.tableau()[d_aventurier->position().x()][d_aventurier->position().y()-1] != '#')

            d.deplaceUp(d_aventurier);
         break;
    case 4 :// se deplacer en bas
        if( d_terrain.tableau()[d_aventurier->position().x()][d_aventurier->position().y()+1] != 'x'
            && d_terrain.tableau()[d_aventurier->position().x()][d_aventurier->position().y()+1] != '#')

            d.deplaceDown(d_aventurier);
        break;
    case 5 : //se deplacer en haut vers la gauche 'lu'
        if( d_terrain.tableau()[d_aventurier->position().x()-1][d_aventurier->position().y()-1] != 'x'
            && d_terrain.tableau()[d_aventurier->position().x()-1][d_aventurier->position().y()-1] != '#')

            d.deplaceLeftUp(d_aventurier);
        break;
    case 6 ://se deplacer en haut vers la droite 'ru'
        if( d_terrain.tableau()[d_aventurier->position().x()+1][d_aventurier->position().y()-1] != 'x'
            && d_terrain.tableau()[d_aventurier->position().x()+1][d_aventurier->position().y()-1] != '#')

            d.deplaceRightUp(d_aventurier);
        break;
    case 7 ://se deplacer en bas vers la gauche 'ld'
          if( d_terrain.tableau()[d_aventurier->position().x()-1][d_aventurier->position().y()+1] != 'x'
            && d_terrain.tableau()[d_aventurier->position().x()-1][d_aventurier->position().y()+1] != '#')

            d.deplaceLeftDown(d_aventurier);
         break;
    case 8 :// se daplacer en bas vers la droite 'rd'
        if( d_terrain.tableau()[d_aventurier->position().x()+1][d_aventurier->position().y()+1] != 'x'
          && d_terrain.tableau()[d_aventurier->position().x()+1][d_aventurier->position().y()+1] != '#')

            d.deplaceRightDown(d_aventurier);
         break;
    }

}
