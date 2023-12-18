#ifndef ACTEUR_H_INCLUDED
#define ACTEUR_H_INCLUDED

#include<iostream>
#include <ostream>

#include "armes.h"


class acteur
{
public:
    virtual ~acteur()= default;
    virtual double point_vie()const;
    virtual double point_force()const;
   virtual void PointVie(double pVie) =0;
    virtual double   Attaque_Avec_Force() =0;
//    virtual void EstAttaque(double force )=0;
//    /**reste a voir*/
    virtual void attaque( acteur& act) =0;
//    virtual void SeDeplace()=0;
     virtual double x() const=0;
     virtual  double y() const=0;
    virtual void symboleActeur() const=0;
     virtual void x (double x)=0;
     virtual void y(double y)=0;

};


/**************************** AVENTURIER *****************************/

class aventurier :public acteur
{
public:
    aventurier(double vie, double force,double bourse, double stabiliteEpee, double stabiliteArmure );
    double point_vie() const override;
    void PointVie(double pVie) override;

    double point_force() const override;
    double bourse() const;
    double Attaque_Avec_Force() override;
    void Tue_Monstre (acteur& Monstre);
    bool estMort() const;
    double SoliditeEpee() const;
    void pSoliditeEpee(double p);
    //void EstAttaque( double force ) override;
     /**reste a voir*/
//    void SeDeplace() override;
     void attaque(acteur& act) override;
    /** */
    double x() const override;
    double y() const override;
    void x (double x) override;
    void y(double y) override;
    void symboleActeur() const override;
private:

 double d_pvie, d_pforce, d_x, d_y;
 double d_bourse;
 armes d_Epee;
 armes d_Armure;
};


 /**   ***********************    MONSTRE   ********************/

class monstre:public acteur
{public:
    monstre(double pointVie,double pointForce, double habilite );
    double habilite() const ;
    double point_vie() const override;
    void PointVie(double pVie) override;
    double point_force() const override;
    double  Attaque_Avec_Force() override;
     bool estMort() const;
    // void attaque(acteur& act) override;
    void attaque(aventurier& a);

      /**reste a voir*/
//    void SeDeplace() override;
//    void ataque(acteur& M) override;
    double x() const override;
    double y() const override;
    void x (double x) override;
    void y(double y) override;
    void symboleActeur() const override;

private:
   double d_pvie, d_pforce, d_x, d_y;
    double d_habilite;

};

class monstreVoyant:public monstre
{public:
 //    void SeDeplace() override;

};
class monstreAveugle: public monstre
{public:
   // void SeDeplace() override;
};

#endif // ACTEUR_H_INCLUDED
