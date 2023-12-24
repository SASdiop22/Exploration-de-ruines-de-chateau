#include "Terrain.h"
#include"monstre.h"
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
terrain::terrain(const std::vector<std::vector<char>>& tableau):d_tableau{tableau}
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
    for(int i = 1; i< hauteur()-1; i+=2)

    {
         std::vector<int>setOfRandomValue;
        setOfRandomValue.push_back(0);
        int caseInacessible =  static_cast<int>(hauteur()/2);
        cout<<'c'<<caseInacessible<<endl;



        while( setOfRandomValue.size()!= (caseInacessible+1))
        {
            int randomValue = (std::rand() % (hauteur() - 2)) + 1;

            if(isAmongValue(setOfRandomValue,randomValue)== false)
            {

                setOfRandomValue.push_back(randomValue);
                 d_tableau[randomValue][i] =  '#';
            }

        }
        cout<<"dans la boucle for"<<endl;


    }
    cout<<"Hors"<<endl;


}
void terrain::initialiserActeur(aventurier& aventurier,std::vector<std::unique_ptr<monstre>>& monstres)
{
    d_tableau[aventurier.position().x()][aventurier.position().y()] = aventurier.symbole();

    for(auto &m: monstres)
    {
        int randomValueLigne = (std::rand() % (largeur() - 2)) + 1;
        cout<<randomValueLigne;
        int randomValueColonne = (std::rand() % (hauteur() - 2)) + 1;
        cout<<randomValueColonne;
        if(d_tableau[randomValueLigne][randomValueColonne] != '#')
        {
           d_tableau[randomValueLigne][randomValueColonne] = m->symbole();
        }


    }

}
