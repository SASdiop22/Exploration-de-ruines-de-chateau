#ifndef ARMES_H_INCLUDED
#define ARMES_H_INCLUDED

class armes{
public:
    armes(double point);
    double solidite() const;
    void Pointsolidite(double point);
private:
    double d_pointSolidite;
};

#endif // ARMES_H_INCLUDED
