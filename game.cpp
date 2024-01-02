#include "game.h"
#include <vector>
#include "iostream"
#include <memory>
#include "random"

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
/**
1- d'abord il faut verifier que la distance <8 case entre lui et l'aventurier
2- verifier que la case est accessibles (il est vide pour faire le deplacement )
3- faire des m_a_j sur le terrain
**/

void game::deplaceMonstreVoyant(  std::unique_ptr<acteur> & M)
{  deplacement  d{};
  /**1- d'abord il faut verifier que la distance <8 case entre lui et l'aventurier*/

      int distanceEnCase= distanceEntreMonstre_Aventurier(M);
       /**pour chaque monstre */
     if(distanceEnCase<=8)
    {   /** on decide d'abord qu'elle direction pour laquelle il va se deriger */

      int directionX = (d_aventurier->position().x() > M->position().x()) ? 1 : (d_aventurier->position().x ()<  M->position().x()) ? -1 : 0;
      int directionY = (d_aventurier->position().y() >  M->position().y()) ? 1 : (d_aventurier->position().y() < M->position().y()) ? -1 : 0;

      /** Déplacer le monstre en fonction de la direction calculée
       avant le deplacement il faut verifier chaquue case si accesssible ou pas
       */

       if (directionX == 1 && directionY == 0) {
            if (CaseAccessible(M->position().x() + 1,M->position().y())) {
            d_terrain.tableau()[M->position().x()][M->position().y()]= ' ';
            d.deplaceRight(M);

            }
        }
       else if (directionX == -1 && directionY == 0) {
             if (CaseAccessible(M->position().x() - 1, M->position().y())) {
             d_terrain.tableau()[M->position().x()][M->position().y()]= ' ';
             d.deplaceLeft(M);

           }
         }
       else if (directionX == 0 && directionY == -1) {
            if (CaseAccessible(M->position().x(), M->position().y() - 1)) {
            d_terrain.tableau()[M->position().x()][M->position().y()]= ' ';
            d.deplaceUp(M);

            }
         }
        else if (directionX == 0 && directionY == 1) {
            if (CaseAccessible(M->position().x(), M->position().y() + 1)) {
              d_terrain.tableau()[M->position().x()][M->position().y()]= ' ';
                d.deplaceDown(M);

            }
        }
      }
      else
        {

          int direction= rand()%4;  //0:RIGHT   1:LEFT   2:UP   3:DOWN
          switch (direction) {
            case 0:
                 if (CaseAccessible(M->position().x() + 1,M->position().y()))
                 {   d_terrain.tableau()[M->position().x()][M->position().y()]= ' ';
                     d.deplaceRight(M);
                 }
                break;
            case 1:

                  if (CaseAccessible(M->position().x() - 1, M->position().y())) {
                     d_terrain.tableau()[M->position().x()][M->position().y()]= ' ';
                      d.deplaceLeft(M);
                      }
                break;
            case 2:

                if (CaseAccessible(M->position().x(), M->position().y() - 1)) {
                 d_terrain.tableau()[M->position().x()][M->position().y()]= ' ';
                d.deplaceUp(M);

                  }
                break;
            case 3:
                 if (CaseAccessible(M->position().x(), M->position().y() + 1)) {
                 d_terrain.tableau()[M->position().x()][M->position().y()]= ' ';
                d.deplaceDown(M);
                }
                break;
           }
        }
}


/** je calcul la distance entre un monstre donné et  notre aventurier */

int game::distanceEntreMonstre_Aventurier(std::unique_ptr<acteur>& M) const

 {int deltaX= static_cast<int>(std::abs(d_aventurier->position().x() - M->position().x()));
   int deltaY= static_cast<int>(std::abs(d_aventurier->position().y() - M->position().y()));
   return std::max(deltaX, deltaY); // Utilisation du maximum pour la distance en cases
}


/** fonction pour  verifier qu' une case de terrain est accessible ou pas */


bool game::CaseAccessible(int x, int y) const
{
   return d_terrain.estCaseAccessible(x, y);
}
