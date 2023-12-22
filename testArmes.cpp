#include "doctest.h"
#include "armes.h"
TEST_CASE("L'armes fonctionne correctement")
{
    SUBCASE("Creation d'un arme fontionne")
    {
        armes Epee{100};
        REQUIRE_EQ(Epee.points_de_solidite(), 100);
    }
    SUBCASE("Un arme gagne bien de points de solidite")
    {
        armes Epee{100};
        Epee.gain_de_pointSolidite(20);
        REQUIRE_EQ(Epee.points_de_solidite(),120);
    }
    SUBCASE("Un arme gagne bien de points de solidite")
    {
        armes Epee{100};
        Epee.perte_de_pointSolidite(20);
        REQUIRE_EQ(Epee.points_de_solidite(), 80);
    }
}
