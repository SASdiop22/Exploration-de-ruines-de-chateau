#ifndef DEPLACEMENT_H_INCLUDED
#define DEPLACEMENT_H_INCLUDED
#include "acteur.h"
#include <memory>

class deplacement
{
public:
    deplacement();
     void deplaceRight(std::unique_ptr<acteur>& A);
    void deplaceLeft(std::unique_ptr<acteur>& A);
    void deplaceUp(std::unique_ptr<acteur>& A);
    void deplaceDown(std::unique_ptr<acteur>& A);
    void deplaceRightUp(std::unique_ptr<acteur>& A);
    void deplaceRightDown(std::unique_ptr<acteur>& A);
    void deplaceLeftUp(std::unique_ptr<acteur>& A);

};


#endif // DEPLACEMENT_H_INCLUDED
