#include "game.h"
#include<vector>
#include<string>
#include<ctime>
#include<cstdlib>
#include<iostream>
#include <random>
#include <chrono>
#include"deplacement.h"
#include"acteur.h"

using std::vector;
using std::string;
//std::random_device rd;
unsigned valeur = std::chrono::system_clock::now().time_since_epoch().count();
//std::mt19937 gen(rd());
std::default_random_engine val(valeur);

game::game(): d_aventurier {}, d_monstres {}, d_terrain {}
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

void game::deplaceMonstreAveugle(std::unique_ptr<acteur> & M)
{
    deplacement d{};

        bool moveRight = false;
        bool moveLeft = false;
        bool moveUp=false;
        bool moveDown=false;
        bool moveRightUp=false;
        bool moveRightDown=false;
        bool moveLeftUp=false;
        bool moveLeftDown=false;
        string deplacementAveugle;

        if(d_terrain.tableau()[M->position().x()+1][M->position().y()] != '#')//est ce que le monstre peut aller à droite
        {
            moveRight =  true;
        }
        if(d_terrain.tableau()[M->position().x()-1][M->position().y()] != '#')//est ce que le monstre peut aller à gauche
        {
            moveLeft =  true;
        }
        if(d_terrain.tableau()[M->position().x()][M->position().y()-1] != '#')//est ce que le monstre peut aller à haut
        {
            moveUp =  true;
        }
        if(d_terrain.tableau()[M->position().x()][M->position().y()+1] != '#')//est ce que le monstre peut aller à bas
        {
            moveDown =  true;
        }
        if(d_terrain.tableau()[M->position().x()+1][M->position().y()-1] != '#')//est ce que le monstre peut aller à droite en haut
        {
            moveRightUp =  true;
        }
        if(d_terrain.tableau()[M->position().x()+1][M->position().y()+1] != '#')//est ce que le monstre peut aller à droite en bas
        {
            moveRightDown =  true;
        }
        if(d_terrain.tableau()[M->position().x()-1][M->position().y()-1] != '#')//est ce que le monstre peut aller à gauche en haut
        {
            moveLeftUp =  true;
        }
        if(d_terrain.tableau()[M->position().x()-1][M->position().y()+1] != '#')//est ce que le monstre peut aller à gauche en haut
        {
            moveLeftDown =  true;
        }

        bool deplacementImpossible ;
        do
        {
            std::vector<string> listeDesDeplacements{"Right","Left","Up","Down","Right Up","Right Down","Left Up","Left Down"};

            std::uniform_int_distribution<int> distrib(0, listeDesDeplacements.size()-1);
            int randomMove = distrib(val);
            deplacementAveugle = listeDesDeplacements[randomMove];
            if(deplacementAveugle == "Right" && moveRight == true)
            {
                deplacementImpossible = false;
            }
            else if(deplacementAveugle == "Left" && moveLeft== true)
            {
                deplacementImpossible = false;
            }
            else if(deplacementAveugle == "Up" && moveUp== true)
            {
                deplacementImpossible = false;
            }
            else if(deplacementAveugle == "Down" && moveDown== true)
            {
                deplacementImpossible = false;
            }
            else if(deplacementAveugle == "Right Up" && moveRightUp== true)
            {
                deplacementImpossible = false;
            }
            else if(deplacementAveugle == "Right Down" && moveRightDown== true)
            {
                deplacementImpossible = false;
            }
            else if(deplacementAveugle == "Left Up" && moveLeftUp== true)
            {
                deplacementImpossible = false;
            }
            else if(deplacementAveugle == "Left Down" && moveLeftDown== true)
            {
                deplacementImpossible = false;
            }
            else
            {
                deplacementImpossible = true;
            }

        }
        while(deplacementImpossible == true);


            if(deplacementAveugle ==  "Right")
            {
                d_terrain.tableau()[M->position().x()][M->position().y()]= ' ';
                d.deplaceRight(M);
            }

            else if(deplacementAveugle ==  "Left")
            {
                d_terrain.tableau()[M->position().x()][M->position().y()]= ' ';
                d.deplaceLeft(M);
            }
            else if(deplacementAveugle ==  "Up")
            {
                d_terrain.tableau()[M->position().x()][M->position().y()]= ' ';
                d.deplaceUp(M);
            }
            else  if(deplacementAveugle ==  "Down")
            {
                d_terrain.tableau()[M->position().x()][M->position().y()]= ' ';
                d.deplaceDown(M);
            }
            else  if(deplacementAveugle ==  "Right Up")
            {
                d_terrain.tableau()[M->position().x()][M->position().y()]= ' ';
                d.deplaceRightUp(M);
            }
            else  if(deplacementAveugle ==  "Right Down")
            {
                d_terrain.tableau()[M->position().x()][M->position().y()]= ' ';
                d.deplaceRightDown(M);
            }
            else  if(deplacementAveugle ==  "Left Up")
            {
                d_terrain.tableau()[M->position().x()][M->position().y()]= ' ';
                d.deplaceLeftUp(M);
            }

            else if(deplacementAveugle ==  "Left Down")
            {
                d_terrain.tableau()[M->position().x()][M->position().y()]= ' ';
                d.deplaceLeftDown(M);

            }





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


