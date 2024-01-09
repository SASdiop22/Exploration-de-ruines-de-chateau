#include "Terrain.h"
#include"monstre.h"
#include<ctime>
#include<cstdlib>
#include<iostream>
#include <random>
#include <chrono>

using std::cout;
using std::endl;
//std::random_device rd;
unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
//std::mt19937 gen(rd());
std::default_random_engine gen(seed);


bool isAmongValue(std::vector<int>setOfRandomValue, int randomValue)
{
    int i = 0;
    while (i < setOfRandomValue.size())
    {
        if (setOfRandomValue[i] != randomValue)
        {
            i++;
        }
        else
        {
            return true;
        }
    }
    return false;
}

std::vector<std::vector<char>> terrain::tableau() const
{
    return d_tableau;
}
terrain::terrain(int largeur,int hauteur)
{
    d_tableau.resize(largeur,std::vector<char>(hauteur));
//    d_tableau.resize(hauteur);
//    for(int i=0; i<d_tableau.size(); i++)
//    {
//
//        d_tableau[i].resize(largeur);
//
//    }

}
//nombre de colonnes
int terrain::largeur() const
{
return d_tableau.size();


}
//bombres de lignes
int terrain::hauteur() const
{
    return d_tableau[0].size();
}

void terrain::attribuerMurTerrain()
{

    for (int i = 0; i < hauteur(); i++)
    {
        d_tableau[0][i] = 'x';
        d_tableau[largeur() - 1][i] = 'x';

    }

    for (int j = 0; j < largeur(); j++)
    {
        if(j != 1)
        {
            d_tableau[j][0] = 'x';

        }
        if(j != largeur()-2)
        {
            d_tableau[j][hauteur() - 1] = 'x';

        }
    }

    for(int i = 2; i< hauteur()-1; i+=2)
    {
        std::vector<int>PoistionsOccupees;
        PoistionsOccupees.push_back(0);
        int caseInacessible =  static_cast<int>(hauteur()/5);

        while( PoistionsOccupees.size()!= (caseInacessible+1))
        {
            std::uniform_int_distribution<int> distrib(1, largeur()-2);
            int randomValue = distrib(gen);
            //int  randomValue= (std::rand() % (hauteur() - 2)) + 1;

            if(isAmongValue(PoistionsOccupees,randomValue)== false)
            {

                if((randomValue == largeur()-2 && i == hauteur()-2) )
                {
                    d_tableau[randomValue][i] =  ' ';
                }
                else
                {
                    PoistionsOccupees.push_back(randomValue);
                    d_tableau[randomValue][i] =  '#';

                }

            }

        }

    }

}
void terrain::effacerActeur(acteur& act)
{
     d_tableau[act.position().y()][act.position().x()] = ' ';
}

void terrain::miseAJourActeur(acteur& act)
{
    d_tableau[act.position().y()][act.position().x()] = act.symbole();
}


void terrain::initialiserActeur(std::unique_ptr<aventurier>& aventurier,std::vector<std::unique_ptr<monstre>>& monstres)
{

    d_tableau[aventurier->position().y()][aventurier->position().x()] = aventurier->symbole();
    int i = 0;


    while (i < monstres.size())
    {
        int randomValueLigne, randomValueColonne;

        std::uniform_int_distribution<int> distrib1(2, largeur()-1);
        randomValueLigne = distrib1(gen);
        std::uniform_int_distribution<int> distrib2(2, hauteur()-1);
        randomValueColonne = distrib2(gen);
       // cout << "in " << "rl " << randomValueLigne << "rc " << randomValueColonne << endl;
        if (d_tableau[randomValueLigne][randomValueColonne] == '\0')
        {
            d_tableau[randomValueLigne][randomValueColonne] = monstres[i]->symbole();
            monstres[i]->changePosition(randomValueColonne,randomValueLigne);

            i++;
        }

    }
}

bool terrain::estCaseAccessibleM(int ligne, int colonne) const
{
    return d_tableau[ligne][colonne] != '#' && d_tableau[ligne][colonne] !=  'x' && d_tableau[ligne][colonne] !=  'M' && d_tableau[ligne][colonne] !=  'm';

}
bool terrain::estCaseAccessibleA(int ligne, int colonne) const
{
    return d_tableau[ligne][colonne] != '#' && d_tableau[ligne][colonne] !=  'x';
}
