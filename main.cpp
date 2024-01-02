#include <iostream>
#include "Terrain.h"
#include <memory>
#include "interface.h"
using namespace std;
int main()
{  point p{3,4};
    monstre m{12,15,p,12.4};
 m.AffichePosition();



    return 0;
}
