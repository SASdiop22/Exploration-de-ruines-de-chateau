#ifndef ARMES_H_INCLUDED
#define ARMES_H_INCLUDED

class armes{
public:
    armes(double point);
    double points_de_solidite() const;
    void gain_de_pointSolidite(double point);
    void perte_de_pointSolidite(double point);
private:
    double d_pointSolidite;
};

#endif // ARMES_H_INCLUDED
