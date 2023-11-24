#ifndef ACTEUR_H_INCLUDED
#define ACTEUR_H_INCLUDED

#include<iostream>
#include <ostream>

class acteur
{
public:
    virtual ~acteur()= default;
    virtual double point_vie()const = 0;
    virtual double point_force()const=0;
    virtual void ForceAttaque()=0;
    virtual void EstAttaque(double force )=0;
    virtual void SeDeplace()=0;
    /**position x et y comme methode */
};



class aventurier:public acteur
{
public:
    aventurier(double vie, double force,double bourse, double stabiliteEpee, double stabiliteArmure );
    double point_vie() const override;
    double point_force() const override;
    double  ForceAttaque() override;
    void EstAttaquee( double force ) override;
    void SeDeplace() override;
private:
 double  d_pvie, d_pforce;
 double d_bourse;
 epee d_Epee;
 armure d_Armure;
};

class monstre:public acteur
{public:
    monstre(double pointVie,double pointForce, double habilite );
    double habilite() const ;
    double point_vie() const override;
    double point_force() const override;
private:
    double d_pvie, d_pforce;
    double d_habilite;

};

class monstreVoyant:public monstre
{public:
    void SeDeplace() override;

};
class monstreAveugle: public monstre
{public:
    void SeDeplace() override;
};

#endif // ACTEUR_H_INCLUDED
