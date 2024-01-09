#ifndef INTERFACE_H_INCLUDED
#define INTERFACE_H_INCLUDED

#include"Terrain.h"
#include"aventurier.h"
#include"monstre.h"
#include"deplacement.h"

class interface{
public :
//virtual ~interface() = default;
    virtual void afficheTerrain1(const terrain& T) const = 0;
    virtual void afficheTerrain(const terrain& T) const = 0;
};

class interfaceConsole : public interface
{
    public:
    void afficheTerrain1(const terrain& T) const override ;
    void afficheTerrain(const terrain& T) const override ;
   void MenuPrincipal();
   void afficheInfoAventurier(std::unique_ptr<aventurier> &a);
   void afficheInfoMonstre(std::unique_ptr<monstre>& m);
   void MenuJeu();
   void DimensionTerrain(int &largeur,int hauteur);
    void sauvegarderTerrain(const terrain& t, const std::string& nomFichier);
    std::vector<std::vector<char>> chargerTerrain(const std::string& nomFichier);

};

#endif // INTERFACE_H_INCLUDED
