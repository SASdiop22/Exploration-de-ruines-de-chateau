#include "Terrain.h"
#include"monstre.h"
#include"amulette.h"
#include<ctime>
#include<cstdlib>
#include<iostream>
using std::cout;
using std::endl;


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

bool isAmongValue(const std::vector<std::pair<int, int>>& occupiedPositions, int randomValueLigne, int randomValueColonne)
{
    for (const auto& position : occupiedPositions)
    {
        if (position.first == randomValueLigne && position.second == randomValueColonne)
        {
            return true;
        }
    }
    return false;
}
terrain::terrain():d_tableau{}
{

}
std::vector<std::vector<char>> terrain::tableau() const
{
    return d_tableau;

}
terrain::terrain(int largeur,int hauteur)
{
    d_tableau.resize(hauteur);
    for (int i = 0; i < hauteur; i++)
    {
        d_tableau[i].resize(largeur);

    }

}
int terrain::largeur() const
{
    return d_tableau.size();
}
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

    for (int j = 0; j < hauteur(); j++)

    {
        if(j != 1)
        {
            d_tableau[j][0] = 'x';

        }
        if(j != hauteur()-2)
        {
            d_tableau[j][hauteur() - 1] = 'x';

        }
    }
    for(int i = 2; i< hauteur()-1; i+=2)

    {
        std::vector<int>PoistionsOccupees;
        PoistionsOccupees.push_back(0);
        int caseInacessible =  static_cast<int>(hauteur()/2);

        while( PoistionsOccupees.size()!= (caseInacessible+1))
        {
            int randomValue = (std::rand() % (hauteur() - 2)) + 1;

            if(isAmongValue(PoistionsOccupees,randomValue)== false)
            {

                if(randomValue== largeur()-2 && i == hauteur()-2)
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
void terrain::initialiserActeur(aventurier& aventurier,std::vector<std::unique_ptr<monstre>>& monstres)
{
    d_tableau[aventurier.position().x()][aventurier.position().y()] = aventurier.symbole();
   // std::vector<std::pair<int, int>> posOccupees;

    int monstersPlaced = 0;

    while (monstersPlaced < monstres.size())
{
    int randomValueLigne, randomValueColonne;

    do
    {
        randomValueLigne = (std::rand() % (largeur() - 2)) + 2;
        randomValueColonne = (std::rand() % (hauteur() - 2)) + 2;
        cout << "in " << "rl " << randomValueLigne << "rc " << randomValueColonne << endl;
    }
    while (d_tableau[randomValueLigne][randomValueColonne] == '#' ||
           d_tableau[randomValueLigne][randomValueColonne] == 'M' ||
           d_tableau[randomValueLigne][randomValueColonne] == 'x' );

    d_tableau[randomValueLigne][randomValueColonne] = monstres[monstersPlaced]->symbole();
   // posOccupees.emplace_back(randomValueLigne, randomValueColonne);
    monstersPlaced++;
    cout << "Hors " << "rl " << randomValueLigne << "rc " << randomValueColonne << endl;
}



}

 void terrain::genererPositionAmulette(amulette& amulette){
     int valeurLigne,valeurColonne;
    do
    {
        valeurLigne = (std::rand() % (largeur() - 2)) + 2;
        valeurColonne = (std::rand() % (hauteur() - 2)) + 2;
    }
    while (d_tableau[valeurLigne][valeurColonne] == '#' ||
           d_tableau[valeurLigne][valeurColonne] == 'M' ||
           d_tableau[valeurLigne][valeurColonne] == 'x' );
    d_tableau[valeurLigne][valeurColonne] =amulette.symbole();


 }



