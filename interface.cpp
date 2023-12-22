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

            cout << '|';

            if (terrain.tableau()[i][j] != ' ')
            {
                cout << "  " << terrain.tableau()[i][j] << "  ";
            }
            else
            {
                cout << "    "; // Adjust the spacing for empty cells
            }
        }

        // Print the right border
        cout << '|' << endl;

        // Print the bottom border
        for (int j = 0; j < terrain.hauteur(); j++)
        {
            cout << "+-----";
        }
        cout << '+' << endl;
    }

 }
