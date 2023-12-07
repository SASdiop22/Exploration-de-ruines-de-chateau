armure::armure(double pointSolidite):
    d_pointsSolidite{pointSolidite}
{}

void armure::utiliser() const{
    d_pointsSolidite -= (3 * d_pointsSolodite)/4;
}

void armure::recupererPoint(double point) const {
    d_pointsSoilidite += point;
