#ifndef DEPLACEMENT_H_INCLUDED
#define DEPLACEMENT_H_INCLUDED
#include "acteur.h"
class deplacement
{
public:
    deplacement();
     void deplaceRight(acteur* A);
    void deplaceLeft(acteur* A);
    void deplaceUp(acteur* A);
    void deplaceDown(acteur* A);
    void deplaceRightUp(acteur* A);
    void deplaceRightDown(sacteur* A);
    void deplaceLeftUp(acteur* A);
    void deplaceLeftDown(acteur* A);

};


#endif // DEPLACEMENT_H_INCLUDED
