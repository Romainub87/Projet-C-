
#ifndef GRAPHE_H
#define GRAPHE_H
#include "Arete.h"
#include "Sommet.h"


/// @brief 
class Graphe
{
private:
 /* args */
  std::vector<Sommet> ListSommet = {}
 Arete listArete;
 Sommet listSommet;
public:
    /// @brief 
    /// @param valide 
   

    Sommet ajouterSommet() const;
    Arrete ajouterArrete(cons Sommet &n1, const Sommet Sommet &n2);
    void supprimerSommet( const Sommet &n);
    void supprimerArete(const Arete &e);

    std::set<Sommet> sommets() const;

    std::set<Arete> aretes() const;
    std::set<Sommet> voisins(const Sommet& n) const;
    std::set<Arete> incidentes(const Sommet& n) const;
    Sommet source(const Arete &e) const;
    Sommet destination(const Arete &e) const;
    int degre(const Sommet& n) const;
    int nbSommets() const;
    int nbAretes() const;

   
};

#endif