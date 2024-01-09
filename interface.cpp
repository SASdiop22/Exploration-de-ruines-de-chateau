#include"interface.h"
#include<iostream>
#include <fstream>
#include "point.h"
#include "couleur.h"
using std::cout;
using std::endl;


 void interfaceConsole::afficheTerrain(const terrain& T) const
{

    for (int i = 0; i < T.hauteur(); i++)
    {

        cout << "+-----";

    }
    cout << '+' << endl;
    for (int i = 0; i < T.largeur(); i++)
    {
        for (int j = 0; j < T.hauteur(); j++)
        {


            if (!(i == 1 && j == 0))
            {
#ifdef _WIN32
                HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(hConsole, FOREGROUND_RESET);
#endif
                cout << '|';
            }
            else
            {
                cout << ' ';
            }

            if (T.tableau()[i][j] != ' ')
            {
#ifdef _WIN32
                HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                if (T.tableau()[i][j] == 'x' )
                {
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                }
                else if ( T.tableau()[i][j] == '#')
                {
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                }
                else
                {
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RESET);
                }
#endif
                cout << "  " << T.tableau()[i][j] << "  ";
            }
            else
            {
                cout << "     ";
            }
        }


        if (i != T.largeur() - 2)
        {
#ifdef _WIN32
            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(hConsole, FOREGROUND_RESET);
#endif
            cout << '|' << endl;
        }
        else
        {
            cout << ' ' << endl;
        }


        for (int j = 0; j < T.hauteur(); j++)
        {
#ifdef _WIN32
            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(hConsole, FOREGROUND_RESET);
#endif
            cout << "+-----";
        }
        cout << '+' << endl;
    }

}
void interfaceConsole::afficheTerrain1(const terrain& T) const
{

    for (int i = 0; i < T.hauteur(); i++)
    {

        cout << "+-----";

    }
    cout << '+' << endl;
    for (int i = 0; i < T.largeur(); i++)
    {
        for (int j = 0; j < T.hauteur(); j++)
        {


            if (!(i == 1 && j == 0))
            {
                cout << '|';
            }
            else
            {
                cout << ' ';
            }

            if (T.tableau()[i][j] != ' ')
            {


                if (T.tableau()[i][j] == 'x' )
                {
                    cout << "⬛";
                }
                else if ( T.tableau()[i][j] == '#')
                {
                    cout<< "⬜";
                }
                else if(T.tableau()[i][j] == 'A')
                {
                    cout << "🏰 ";
                }
                else if(T.tableau()[i][j] == 'M')
                {
                    cout << "👾 ";
                }
                else if(T.tableau()[i][j] == 'm')
                {
                    std::cout << "👹 ";
                }
            }
            else
            {
                cout << "     ";
            }
        }
        if (i != T.largeur() - 2)
        {
            cout << '|' << endl;
        }
        else
        {
            cout << ' ' << endl;
        }

        for (int j = 0; j < T.hauteur(); j++)
        {
            cout << "+-----";
        }
        cout << '+' << endl;
    }

}
void sauvegarderTerrain(const terrain& t, const std::string& nomFichier)
{
    // Ouvre le fichier en mode écriture
    std::ofstream fichier(nomFichier);

    if (fichier.is_open())
    {
        // Écrit chaque ligne du terrain dans le fichier
        for (int i = 0; i < t.hauteur(); ++i)
        {
            for (int j = 0; j < t.largeur(); ++j)
            {
                fichier << t.tableau()[j][i];
            }
            fichier << '\n'; // Ajoute un retour à la ligne à la fin de chaque ligne du terrain
        }

        // Ferme le fichier
        fichier.close();
        std::cout << "Terrain sauvegardé avec succès dans le fichier : " << nomFichier << std::endl;
    }
    else
    {
        std::cerr << "Erreur lors de l'ouverture du fichier pour la sauvegarde du terrain." << std::endl;
    }
}

std::vector<std::vector<char>> chargerTerrain(const std::string& nomFichier)
{
    std::vector<std::vector<char>> tableau;

    // Ouvre le fichier en mode lecture
    std::ifstream fichier(nomFichier);

    if (fichier.is_open())
    {
        std::string ligne;

        // Lit chaque ligne du fichier
        while (std::getline(fichier, ligne))
        {
            std::vector<char> ligneTableau;

            // Ajoute chaque caractère de la ligne à la ligne du tableau
            for (char c : ligne)
            {
                ligneTableau.push_back(c);
            }

            // Ajoute la ligne du tableau au tableau global
            tableau.push_back(ligneTableau);
        }

        // Ferme le fichier
        fichier.close();
    }
    else
    {
        std::cerr << "Erreur lors de l'ouverture du fichier pour la récupération du terrain." << std::endl;
    }

    return tableau;
}
void gotoxy(int x, int y)
{
  HANDLE handle;
  COORD coordinates;
  handle = GetStdHandle(STD_OUTPUT_HANDLE);
  coordinates.X = x;
  coordinates.Y = y;
  SetConsoleCursorPosition(handle, coordinates);
}

int LageurDeLaconsole()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int columns, rows;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
    return columns;

}

void interfaceConsole::MenuPrincipal()
{
    int x =  LageurDeLaconsole()/3;
    int choix{-1};
    do
    {
        gotoxy(x,5); cout<<"---------------------------------------";
		gotoxy(x,6); cout<<"|   EXPLORATION  DE RUINES DE CHATEAU  |";
		gotoxy(x,7); cout<<"---------------------------------------";
		gotoxy(x,9); cout<<"[1] DEMARRER LE JEU";
		gotoxy(x,10);cout<<"[2] TUTORIEL";
		gotoxy(x,11);cout<<"[3] QUITTER";
		gotoxy(x,13);cout<<"Selectionner votre choix: ";
		do
        {
            cin>>choix;
            if(choix < 1 || choix >3)
            {
                cout<<"Choix invalide!! Veuillez reessayer"<<endl;
            }
        }
        while(choix < 1 || choix >3);
        switch(choix)
        {
        case 1:
            system("cls");
//            MenuJeu();


            break;
        case 2:
            cout<<"Hi2"<<endl;

            break;
        case 3:
            break;
        }

    }

    while(choix < 1 || choix >3);

}

//void interfaceConsole::creerTerrain()
//{

//}

void interfaceConsole::afficheInfoAventurier(std::unique_ptr<aventurier>& a)
{
   int x =  LageurDeLaconsole()/20;
  gotoxy(3,3);cout<<"Aventurier";
  gotoxy(1,4);cout<<"Points de force:"<<a->pointDeforce();
  gotoxy(1,5);cout<<"Points de vie:"<<a->pointDeforce();
  gotoxy(1,6);cout<<"Bourse de pièces:";
//  gotoxy(1,7);cout<<"Epee":<<a->Epee().points_de_solidite();
//  gotoxy(1,8);cout<<"Armure"<<a->Armure().points_de_solidite();
}
void interfaceConsole::afficheInfoMonstre(std::unique_ptr<monstre>& m)
{
   int x =  LageurDeLaconsole()/3;
  gotoxy(x-2,3);cout<<"Monstre";
  gotoxy(x,4);cout<<"Points de force:"<<m->pointDeforce();
  gotoxy(x,5);cout<<"Points de vie:"<<m->pointDeforce();
  gotoxy(x,6);cout<<"Pourcentage d'habilité"<<m->habilite();

}
void interfaceConsole::MenuJeu()
{
    int x =  LageurDeLaconsole()/3;
    int choix{-1};
    do
    {
        gotoxy(x,5); cout<<"---------------";
		gotoxy(x,6); cout<<"|   MENU JEU   |";
		gotoxy(x,7); cout<<"---------------";
		gotoxy(x,9); cout<<"[1] JEU RAPIDE";
		gotoxy(x,10);cout<<"[2] SPECIFIER LES DIMENSIONS DU TERRAIN";
		gotoxy(x,11);cout<<"[3] REPRENDRE UNE PARTIE";
		gotoxy(x,12);cout<<"[4] RETOUR AU MENU PRINCIPAL";

		gotoxy(x,13);cout<<"Selectionner votre choix: ";
		do
        {
            cin>>choix;
            if(choix < 1 || choix >4)
            {
                cout<<"Choix invalide!! Veuillez reessayer"<<endl;
            }
        }
        while(choix < 1 || choix >4);
        switch(choix)
        {
        case 1:
            system("cls");
//            afficheTerrain();


            break;
        case 2:
            system("cls");

            break;
        case 3:
            break;
        case 4:
            MenuPrincipal();
            break;
        }

    }

    while(choix < 1 || choix >4);

}

void interfaceConsole::DimensionTerrain(int &largeur,int hauteur)
{
    cout<<"Entrer la hauteur du terrain"<<endl;
    cin>>hauteur;
    cout<<"Entrer la largeur du terrain"<<endl;
    cin>>hauteur;
}
