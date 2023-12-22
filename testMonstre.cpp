#include "doctest.h"
#include "monstre.h"
TEST_CASE("Un monstre fonctionne correctement")
{

    SUBCASE("Un monstre est construis correctement")
    {
        point p{10.0,30.0};
        monstre M{200.0,500.0,p,0.5};
        REQUIRE_EQ(M.pointDevie(), 200.0);
        REQUIRE_EQ(M.pointDeforce(), 500.0);
        REQUIRE_EQ(M.position().x(),p.x());
        REQUIRE_EQ(M.position().y(),p.y());
    }
    SUBCASE("La modification des données d'un monstre est correcte")
    {
        point p{10.0,30.0};
        monstre M{200.0,500.0,p,0.5};
        M.ChangePointDeVie(700.0);
        M.ChangePointDeForce(1000.0);
        REQUIRE_EQ(M.pointDevie(), 700.0);
        REQUIRE_EQ(M.pointDeforce(), 1000.0);
    }
    SUBCASE("L'monstre meurt quand il n'a plus de point de vie")
    {
        point p{10.0,30.0};
        monstre M{200.0,500.0,p,0.5};
        M.ChangePointDeVie(0.0);
        REQUIRE_UNARY(M.estMort());
    }
    SUBCASE("Pour une attaque")
        {
            SUBCASE("Le monstre réalise bien son attaque avec la force qu'il faut")
            {
                armes epee{100.0};
                armes armure{120.0};
                point position{10.0,10.0};
                monstre M{200.0,500.0,position,0.5};
                double forceAttque1 = 500.0*0.5*0.9;
                double forceAttaque = M.ForceDAttaque();
                //REQUIRE_EQ(A.ForceDAttaque(),forceAttque1);
                REQUIRE_UNARY(forceAttaque ==  forceAttque1);
            }
            SUBCASE("monstre subit les dégats d'une attaque d'aventurier")
            {
                armes epee{100.0};
                armes armure{120.0};
                point position{10.0,10.0};
               aventurier A{200.0,500.0,position,epee,armure};
                monstre M{100,300,position,0.8};
                double f = A.ForceDAttaque();
                A.attaque(M);
                REQUIRE_EQ(M.pointDevie(),100-f);

            }
        }
}
