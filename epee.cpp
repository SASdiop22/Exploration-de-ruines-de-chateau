
epep::epee(double pointSolidite):
    d_pointsSolidite{pointSolidites}
{}

void epee::utiliser()const{
    d_pointsSoldite -= 1;

}
void epee::recupererPoint(int point) const{
    d_pointsSoldite += point;
}
