armes::armes(double point):
    d_pointSolidite {point}
{}

double armes::solidite() const{
    return d_pointSolidite;
}
void armes::Pointsolidite(double point){
     d_pointSolidite{point};
}
