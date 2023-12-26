#ifndef DEPLACEMENT_H_INCLUDED
#define DEPLACEMENT_H_INCLUDED
#include "acteur.h"
class deplacement
{
public:
    deplaceRight(std::unique_ptr<acteur> A);
    deplaceLeft(std::unique_ptr<acteur> A);
    deplaceUp(std::unique_ptr<acteur> A);
    deplaceDown(std::unique_ptr<acteur> A);
    deplaceRightUp(std::unique_ptr<acteur> A);
    deplaceRightDown(std::unique_ptr<acteur> A);
    deplaceLeftUp(std::unique_ptr<acteur> A);
    deplaceLeftDown(std::unique_ptr<acteur> A);

};


#endif // DEPLACEMENT_H_INCLUDED
