#include"armes.h"

armes::armes(double point):
    d_pointSolidite {point}
{}

double armes::points_de_solidite() const{
    return d_pointSolidite;
}
void armes::gain_de_pointSolidite(double point){
     d_pointSolidite += point;
}
void armes::perte_de_pointSolidite(double point){
     d_pointSolidite -= point;
}


