 #include"interface.h"
 #include<iostream>
using std::cout;
using std::endl;

 void interfaceConsole::initialiserTerrain( terrain &terrain) const{

    terrain.attribuerMurTerrain();
    for (int i = 0; i < terrain.hauteur(); i++)
    {

        cout << "+-----";

    }
    cout << '+' << endl;
    for (int i = 0; i < terrain.largeur(); i++)
    {
        for (int j = 0; j < terrain.hauteur(); j++)
        {


            if (!(i == 1 && j == 0))
            {
                cout << '|';
            }
            else
            {
                cout << ' ';
            }

            if (terrain.tableau()[i][j] != ' ')
            {
                cout << "  " << terrain.tableau()[i][j] << "  ";
            }
            else
            {
                cout << "     ";
            }
        }


        if (i != terrain.largeur() - 2)
        {
            cout << '|' << endl;
        }
        else
        {
            cout << ' ' << endl; // Adjust the spacing for the second-to-last row
        }

        // Print the bottom border
        for (int j = 0; j < terrain.hauteur(); j++)
        {
            cout << "+-----";
        }
        cout << '+' << endl;
    }
 }
void interfaceConsole::initialiserActeur(terrain& terrain,aventurier& aventurier,std::unique_ptr<monstre> monstres) const
{
    cout<<aventurier.symbole();
}
