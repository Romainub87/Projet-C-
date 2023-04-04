#ifndef GRAPHE_H
#define GRAPHE_H

#include "Arete.h"
#include "Sommet.h"
#include <string>
#include <set>
#include <map>
class Graphe
{
private:
    std::set<Sommet> m_sommets;
    std::set<Arete> m_aretes;
public:
    std::set<Sommet> sommets() const;
    std::set<Arete> aretes() const;
    std::set<Sommet> voisins(const Sommet &n) const;
    std::set<Arete> incidentes(const Sommet &n) const;
    Sommet source(const Arete &e) const;
    Sommet destination(const Arete &e) const;
    int degre(const Sommet &n) const;
    int nbSommets() const;
    int nbAretes() const;
    virtual Sommet ajouterSommet();
    virtual Arete ajouterArete(const Sommet &n1, const Sommet &n2);
    virtual void supprimerSommet(const Sommet &n);
    virtual void supprimerArete(const Arete &e);
    virtual bool charger(std::string fichier) ;
    static std::map<Arete, std::pair<Sommet, Sommet>> aretes2Extremites;
    static std::map<Sommet, std::set<Arete>> sommets2Incidentes;
};

#endif