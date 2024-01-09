#include"Terrain.h"
#include"interface.h"
#include"aventurier.h"
#include "point.h"
#include "deplacement.h"
#include "game.h"
#include<memory>
using namespace std;

int main()
{

    game G{};

    std::unique_ptr<aventurier> a = std::make_unique<aventurier>();
    std::unique_ptr<monstre> m1 = std::make_unique<monstreVoyant>();
//    std::unique_ptr<monstre> m2 =std::make_unique<monstreVoyant>();
    std::unique_ptr<monstre> m3 = std::make_unique<monstreAveugle>();
    G.ajoute(std::move(a));
    G.ajoute(std::move(m1));
//    G.ajoute(std::move(m2));
    G.ajoute(std::move(m3));

    G.run();

    return 0;
}




