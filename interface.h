#ifndef INTERFACE_H_INCLUDED
#define INTERFACE_H_INCLUDED

#include"Terrain.h"
#include"aventurier.h"
#include"monstre.h"
#include"deplacement.h"

class interface{
public :
virtual ~interface() = default;
    virtual void afficheTerrain() const = 0;
};

class interfaceConsole : public interface
{
    public:
    void afficheTerrain() const override ;
   void MenuPrincipal();



};

#endif // INTERFACE_H_INCLUDED
