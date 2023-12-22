#ifndef INTERFACE_H_INCLUDED
#define INTERFACE_H_INCLUDED

#include"Terrain.h"
class interface{
public :
virtual ~interface() = default;
    virtual void initialiserTerrain( terrain &terrain) const = 0;
};

class interfaceConsole : public interface
{
    void initialiserTerrain( terrain &terrain) const override ;

};

#endif // INTERFACE_H_INCLUDED
