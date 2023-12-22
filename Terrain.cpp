#include "Terrain.h"


terrain::terrain(const std::vector<std::vector<char>>& tableau):d_tableau{tableau}
{

}
std::vector<std::vector<char>> terrain::tableau() const
{
    return d_tableau;

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

    for (int j = 0; j < largeur(); j++)
    {
        d_tableau[j][0] = 'x';
        d_tableau[j][hauteur() - 1] = 'x';
    }

}
