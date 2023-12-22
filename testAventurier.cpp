#include "doctest.h"
#include "aventurier.h"
TEST_CASE("Un aventurier fonctionne correctement")
{
    SUBCASE(" la construction d'un aventurier est correcte")
    {
        SUBCASE("Par defaut")
        {
            aventurier A{};
            REQUIRE_EQ(A.pointDeVie(), 1000);
            REQUIRE_EQ(A.pointDeForce(), 1000);
        }
        SUBCASE("Avec des parametres")
        {
            aventurier A{200,500,100,100};
            REQUIRE_EQ(A.pointDeVie(), 200);
            REQUIRE_EQ(A.pointDeForce(), 500);
        }
    }
    SUBCASE("Les methodes de l'aventurier sont correctes")
    {
        SUBCASE("Renvoyer les points de vie est correcte")
        {
            aventurier A{200,500,100,120};
            REQUIRE_EQ(A.pointDeVie(),200);
        }
        SUBCASE("Renvoyer les points de force est correcte")
        {
            aventurier A{200,500,100,120};
            REQUIRE_EQ(A.pointDeForce(),500);
        }
        SUBCASE("Renvoyer les points de solidité de l'épée est correcte")
        {
            aventurier A{200,500,100,120};
            REQUIRE_EQ(A.pointSoliditeEpee(),100);
        }
        SUBCASE("Renvoyer les points de solidité de l'armure est correcte")
        {
            aventurier A{200,500,100,120};
            REQUIRE_EQ(A.pointSoliditeEpee(),120);
        }
        SUBCASE("Pour une attaque")
        {
            SUBCASE("L'aventurier subit les deja d'un attaque")
            {
                aventurier A{200,500,100,100};
                monstre M{100,300,0.8};
                A.attaque(M);
                REQUIRE_NE(A.PointSoliditéEpee(),100);

            }
            SUBCASE("L'avennturier réalise bien son attaque avec la force qu'il faut")
            {
                aventurier A{200,500,100,120};
                double forceAttque1 = (500+100)*0,9;
                double forceAttaque2 = 500+100;
                REQUIRE_UNARY(A.forceDAttaque() ==  forceAttque1 || A.forceDAttaque() ==  forceAttque2);
            }
            SUBCASE("L'aventurier subit les dégats d'une attaque de monstre")
            {
                aventurier A{200,500,100,120};
                monstre M{100,300,0.8};
                M.attaque(A);
                REQUIRE_NE(A.PointSoliditéArmure(),120);
                REQUIRE_NE(A.pointDeForce(),200);
            }

        }


    }
}
