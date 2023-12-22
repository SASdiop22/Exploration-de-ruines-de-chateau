#include "doctest.h"
#include "acteur.h"
TEST_CASE("Un acteur fonctionne correctement")
{

    SUBCASE("Un acteur est construis correctement")
    {
        point p{10.0,30.0};
        acteur A{200,500,p};
        REQUIRE_EQ(A.pointDeVie(), 200);
        REQUIRE_EQ(A.pointDeForce(), 500);
        REQUIRE_EQ(A.position().x(),p.x());
        REQUIRE_EQ(A.position().y(),p.y());
    }
    SUBCASE("La modification des données d'un acteur est correcte")
    {
        point p{10.0,30.0};
        acteur A{200,500,p};
        A.ChangePointDeVie(700);
        A.ChangePointDeForce(1000);
        REQUIRE_EQ(A.pointDeVie(), 700);
        REQUIRE_EQ(A.pointDeForce(), 1000);
    }
    SUBCASE("L'acteur meurt quand il le faut")
    {
        point p{10.0,30.0};
        acteur A{200,500,p};
        A.ChangePointDeVie(0);
        REQUIRE_UNARY(A.estMort());
    }
}
