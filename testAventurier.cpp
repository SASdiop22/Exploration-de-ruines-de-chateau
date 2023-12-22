#include "doctest.h"
#include "aventurier.h"
#include "armes.h"
#include "point.h"
#include "monstre.h"
TEST_CASE("Un aventurier fonctionne correctement")
{
    SUBCASE(" la construction d'un aventurier est correcte")
    {
//        SUBCASE("Par defaut")
//        {
//            aventurier A{};
//            REQUIRE_EQ(A.pointDeVie(), 1000);
//            REQUIRE_EQ(A.pointDeForce(), 1000);
//        }
        SUBCASE("Avec des parametres")
        {
            armes epee{100};
            armes armure{100};
            point p{10.0,10.0};
            aventurier A{200,500,p,epee,armure};
            REQUIRE_EQ(A.pointDevie(), 200);
            REQUIRE_EQ(A.pointDeforce(), 500);
            REQUIRE_EQ(A.position().x(),p.x());
            REQUIRE_EQ(A.position().y(),p.y());
        }
    }
    SUBCASE("Les methodes de l'aventurier sont correctes")
    {
//        SUBCASE("Renvoyer les points de vie est correcte")
//        {

//        }
//        SUBCASE("Renvoyer les points de force est correcte")
//        {
//            aventurier A{200,500,100,120};
//            REQUIRE_EQ(A.pointDeForce(),500);
//        }
        SUBCASE("Renvoyer les points de solidité de l'épée et de l'armure est correcte")
        {
            armes epee{100.0};
            armes armure{120.0};
            point position{10.0,10.0};
            aventurier A{200.0,500.0,position,epee,armure};
            REQUIRE_EQ(A.pointDevie(),200.0);
            REQUIRE_EQ(A.pointSoliditeEpee(),100.0);
            REQUIRE_EQ(A.pointSoliditeArmure(),120.0);
        }
        SUBCASE("Pour une attaque")
        {
            SUBCASE("L'epee de l'aventurier subit les degats de son attaque")
            {
                armes epee{100.0};
                armes armure{120.0};
                point position{10.0,10.0};
                aventurier A{200.0,500.0,position,epee,armure};
                monstre M{100.0,300.0, position,0.8};
                A.attaque(M);
                REQUIRE_NE(A.pointSoliditeEpee(),100.0);

            }
            SUBCASE("L'avennturier réalise bien son attaque avec la force qu'il faut")
            {
                armes epee{100.0};
                armes armure{120.0};
                point position{10.0,10.0};
                aventurier A{200.0,500.0,position,epee,armure};
                double forceAttque1 = (500.0+100.0)*0.9;
                double forceAttaque2 = 500.0+100.0;
                double forceAttaque = A.ForceDAttaque();
                //REQUIRE_EQ(A.ForceDAttaque(),forceAttque1);
                REQUIRE_UNARY(forceAttaque ==  forceAttque1 || forceAttaque ==  forceAttaque2);
            }
            SUBCASE("L'aventurier subit les dégats d'une attaque de monstre")
            {
                armes epee{100.0};
                armes armure{120.0};
                point position{10.0,10.0};
                aventurier A{200.0,500.0,position,epee,armure};
                monstre M{100,300,position,0.8};
                //double f = M.ForceDAttaque();

                M.attaque(A);
                REQUIRE_NE(A.pointSoliditeArmure(),120);
                REQUIRE_NE(A.pointDeforce(),200);
            }

        }


    }
}
