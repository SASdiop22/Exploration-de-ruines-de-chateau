#include"deplacement.h"
#include <random>
#include <chrono>
#include <conio.h>
unsigned valeur = std::chrono::system_clock::now().time_since_epoch().count();

std::default_random_engine val(valeur);
void deplacement::deplace(std::unique_ptr<aventurier>& A, terrain &t)
{
    double x = A->position().x();
    double y = A->position().y();
    int choix;
    std::cin>>choix;
    switch (choix)
    {
    case 6 ://se deplacer à droit
        if( t.estCaseAccessibleA(A->position().y(),A->position().x()+1))
        {
            t.effacerActeur(*A);
            A->changePosition(x+1,y);
            t.miseAJourActeur(*A);
        }
        //
        break;
    case 4 ://se deplacer à gauche
        if(t.estCaseAccessibleA(A->position().y(),A->position().x()-1))
        {
           t.effacerActeur(*A);
            A->changePosition(x-1,y);
            t.miseAJourActeur(*A);

        }


        break;
    case 8 ://se deplacer en haut
        if( t.estCaseAccessibleA(A->position().y()-1,A->position().x()))
        {
            t.effacerActeur(*A);
            A->changePosition(x,y-1);
            t.miseAJourActeur(*A);
        }


        break;
    case 2 :// se deplacer en bas
        if(t.estCaseAccessibleA(A->position().y()+1,A->position().x()))
        {
            t.effacerActeur(*A);
            A->changePosition(x,y+1);
            t.miseAJourActeur(*A);
        }
        break;
    case 7 : //se deplacer en haut vers la gauche 'lu'
        if( t.estCaseAccessibleA(A->position().y()-1,A->position().x()-1))
        {
            t.effacerActeur(*A);
            A->changePosition(x-1,y-1);
            t.miseAJourActeur(*A);
        }

        break;
    case 9 ://se deplacer en haut vers la droite 'ru'
        if( t.estCaseAccessibleA(A->position().y()-1,A->position().x()+1))
        {
            t.effacerActeur(*A);
            A->changePosition(x+1,y-1);
            t.miseAJourActeur(*A);
        }


        break;
    case 1 ://se deplacer en bas vers la gauche 'ld'
         if(t.estCaseAccessibleA(A->position().y()+1,A->position().x()-1))
        {
            t.effacerActeur(*A);
            A->changePosition(x-1,y+1);
            t.miseAJourActeur(*A);
        }


        break;
    case 3 :// se daplacer en bas vers la droite 'rd'
       if(t.estCaseAccessibleA(A->position().y()+1,A->position().x()+1))
        {
            t.effacerActeur(*A);
            A->changePosition(x+1,y+1);
            t.miseAJourActeur(*A);
        }
        break;
    }
}
void  deplacement::deplace(std::unique_ptr<monstre>& M, terrain& t)
    {
        double x = M->position().x();
        double y = M->position().y();

        bool moveRight = false;
        bool moveLeft = false;
        bool moveUp=false;
        bool moveDown=false;
        bool moveRightUp=false;
        bool moveRightDown=false;
        bool moveLeftUp=false;
        bool moveLeftDown=false;
        string deplacementAveugle;

        if(t.estCaseAccessibleM(M->position().y(),M->position().x()+1))//est ce que le monstre peut aller à droite
        {
            moveRight =  true;
        }
        if(t.estCaseAccessibleM(M->position().y(),M->position().x()-1))//est ce que le monstre peut aller à gauche
        {
            moveLeft =  true;
        }
        if(t.estCaseAccessibleM(M->position().y()-1,M->position().x()))//est ce que le monstre peut aller à haut
        {
            moveUp =  true;
        }
        if(t.estCaseAccessibleM(M->position().y()+1,M->position().x()))//est ce que le monstre peut aller à bas
        {
            moveDown =  true;
        }
        if(t.estCaseAccessibleM(M->position().y()-1,M->position().x()+1))//est ce que le monstre peut aller à droite en haut
        {
            moveRightUp =  true;
        }
        if(t.estCaseAccessibleM(M->position().y()+1,M->position().x()+1))//est ce que le monstre peut aller à droite en bas
        {
            moveRightDown =  true;
        }
        if(t.estCaseAccessibleM(M->position().y()-1,M->position().x()-1))//est ce que le monstre peut aller à gauche en haut
        {
            moveLeftUp =  true;
        }
        if(t.estCaseAccessibleM(M->position().y()+1,M->position().x()-1))//est ce que le monstre peut aller à gauche en haut
        {
            moveLeftDown =  true;
        }

        bool deplacementImpossible ;
        do
        {
            std::vector<string> listeDesDeplacements{"Right","Left","Up","Down","Right Up","Right Down","Left Up","Left Down"};

            uniform_int_distribution<int> distrib(0, listeDesDeplacements.size()-1);
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
             t.effacerActeur(*M);
             M->changePosition(x+1,y);
             t.miseAJourActeur(*M);
        }

        else if(deplacementAveugle ==  "Left")
        {
            t.effacerActeur(*M);
            M->changePosition(x-1,y);
            t.miseAJourActeur(*M);
        }
        else if(deplacementAveugle ==  "Up")
        {
            t.effacerActeur(*M);
            M->changePosition(x,y-1);
            t.miseAJourActeur(*M);
        }
        else  if(deplacementAveugle ==  "Down")
        {
            t.effacerActeur(*M);
            M->changePosition(x,y+1);
            t.miseAJourActeur(*M);
        }
        else  if(deplacementAveugle ==  "Right Up")
        {
            t.effacerActeur(*M);
            M->changePosition(x+1,y-1);
            t.miseAJourActeur(*M);
        }
        else  if(deplacementAveugle ==  "Right Down")
        {
            t.effacerActeur(*M);
            M->changePosition(x+1,y+1);
            t.miseAJourActeur(*M);
        }
        else  if(deplacementAveugle ==  "Left Up")
        {
            t.effacerActeur(*M);
            M->changePosition(x-1,y-1);
            t.miseAJourActeur(*M);
        }

        else if(deplacementAveugle ==  "Left Down")
        {
            t.effacerActeur(*M);
            M->changePosition(x-1,y+1);
            t.miseAJourActeur(*M);

        }
    }
//    deplace(std::unique_ptr<monstreAveugle>& m, terrain& t);
