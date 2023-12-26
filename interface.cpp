 #include"interface.h"
 #include<iostream>
using std::cout;
using std::endl;
//
//void gotoxy(int x, int y){
//	CursorPosition.X = x;
//	CursorPosition.Y = y;
//	SetConsoleCursorPosition(console, CursorPosition);
//}

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
            cout << ' ' << endl;
        }


        for (int j = 0; j < terrain.hauteur(); j++)
        {
            cout << "+-----";
        }
        cout << '+' << endl;
    }

 }


   void interfaceConsole::MenuPrincipal()
   {
//       gotoxy(10,5);cout<<"----------------------------------------------"<<endl;
//       gotoxy(10,6)cout<<"|      EXPLORATION  DE RUINES DE CHATEAU      |"<<endl;
//       gotoxy(10,5)cout<<"----------------------------------------------"<<endl;
//       gotoxy(10,5)cout<<"1. DEMARRER LE JEU "<<endl;
//      gotoxy(10,5) cout<<" 2. TUTORIEL        "<<endl;
//       gotoxy(10,5)cout<<" 3. TUTORIEL        "<<endl;
//       cout<<" 4. QUITTER LE JEU        "<<endl;



   }
//void interfaceConsole::initialiserActeur(terrain& terrain,aventurier& aventurier) const
//{
//
//
//}
