#ifndef DEPLACEMENT_H_INCLUDED
#define DEPLACEMENT_H_INCLUDED
#include "aventurier.h"
#include "monstre.h"
#include "Terrain.h"
#include <memory>
class deplacement
{
public:
    void deplace(std::unique_ptr<aventurier>& A,terrain &t);
    void deplace(std::unique_ptr<monstre>& M,terrain &t);
    void deplace(std::unique_ptr<monstreAveugle>& m,terrain &t);
};

#endif // DEPLACEMENT_H_INCLUDED
