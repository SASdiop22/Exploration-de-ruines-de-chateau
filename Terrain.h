#ifndef TERRAIN_H_INCLUDED
#define TERRAIN_H_INCLUDED
#include<vector>
class terrain
{

public:
    terrain(const std::vector<std::vector<char>>& tableau);

private:
    std::vector<std::vector<char>>d_tableau;

};

#endif // TERRAIN_H_INCLUDED
