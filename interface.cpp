#include"interface.h"
#include<iostream>
#include "windows.h"
#include "game.h"
using std::cout;
using std::endl;


//void gotoxy(int x, int y){
//	CursorPosition.X = x;
//	CursorPosition.Y = y;
//	SetConsoleCursorPosition(console, CursorPosition);
//}
COORD CursorPosition;

void gotoxy(int x, int y) {
    CursorPosition.X = x;
    CursorPosition.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CursorPosition);
}
 void interfaceConsole::afficheTerrain() const{
     /** Creation du jeu(Game):
        * Creer le terrain par defaut 15x20
        *Creer les monstres et l'ajouter à Game
        *Creer de l'aventurier et l'ajouter à Game
        *Remplir le terrain
    **/
    game G{};
//
//    std::unique_ptr<aventurier> a = std::make_unique<aventurier>();
//    std::unique_ptr<monstre> m1 = std::make_unique<monstre>();
//    std::unique_ptr<monstre> m2 =std::make_unique<monstre>();
//    std::unique_ptr<monstre> m3 = std::make_unique<monstre>();
    /**333333333333*/
      std::unique_ptr<aventurier> a = std::make_unique<aventurier>();
    std::unique_ptr<monstre> m1 = std::make_unique<monstreAveugle>();
    std::unique_ptr<monstre> m2 =std::make_unique<monstreAveugle>();
    std::unique_ptr<monstre> m3 = std::make_unique<monstreVoyant>();
    std::unique_ptr<monstreVoyant>m4=std::make_unique<monstreVoyant>();
    std::unique_ptr<monstreVoyant>m5=std::make_unique<monstreVoyant>();
    std::unique_ptr<monstre> m6 = std::make_unique<monstreVoyant>();
    std::unique_ptr<monstreVoyant>m7=std::make_unique<monstreVoyant>();
    std::unique_ptr<monstreVoyant>m8=std::make_unique<monstreVoyant>();
    G.ajoute(std::move(a));
    G.ajoute(std::move(m1));
    G.ajoute(std::move(m2));
    G.ajoute(std::move(m3));
    /***33333333333*/
    G.ajoute(std::move(m4));
    G.ajoute(std::move(m5));
    G.ajoute(std::move(m6));
    G.ajoute(std::move(m7));
    G.ajoute(std::move(m8));



    G.remplirTerrain();

    terrain  TGame= G.terrainGame();

    for (int i = 0; i < TGame.hauteur(); i++)
    {

        cout << "+-----";

    }
    cout << '+' << endl;
    for (int i = 0; i < TGame.largeur(); i++)
    {
        for (int j = 0; j < TGame.hauteur(); j++)
        {


            if (!(i == 1 && j == 0))
            {
                cout << '|';
            }
            else
            {
                cout << ' ';
            }

            if (TGame.tableau()[i][j] != ' ')
            {
//                if(TGame.tableau()[i][j] == 'M')
//                {
//                    cout << "  " << "\x1B[31m" << TGame.tableau()[i][j] << "\x1B[0m" << "  ";
//                }
//                else
                    cout << "  " << TGame.tableau()[i][j] << "  ";
            }
            else
            {
                cout << "     ";
            }
        }


        if (i != TGame.largeur() - 2)
        {
            cout << '|' << endl;
        }
        else
        {
            cout << ' ' << endl;
        }


        for (int j = 0; j < TGame.hauteur(); j++)
        {
            cout << "+-----";
        }
        cout << '+' << endl;
    }

 }


   void interfaceConsole::MenuPrincipal()
   {
       gotoxy(10,5);cout<<"----------------------------------------------"<<endl;
       gotoxy(10,6);cout<<"|      EXPLORATION  DE RUINES DE CHATEAU      |"<<endl;
       gotoxy(10,5);cout<<"----------------------------------------------"<<endl;
       gotoxy(10,5);cout<<"1. DEMARRER LE JEU "<<endl;
      gotoxy(10,5) ;cout<<" 2. TUTORIEL        "<<endl;
       gotoxy(10,5);cout<<" 3. TUTORIEL        "<<endl;
       cout<<" 4. QUITTER LE JEU        "<<endl;



   }
//void interfaceConsole::initialiserActeur(terrain& terrain,aventurier& aventurier) const
//{
//
//
//}
