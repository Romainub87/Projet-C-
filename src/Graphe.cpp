#include "Graphe.h"
#include "Arete.h"
#include "Sommet.h"
using namespace std;

Graphe::ajouterSommet()
{
    Sommet s;
    Graphe::m_sommets.insert(s);
}


Graphe::ajouterArrete(cons Sommet &n1, const Sommet &n2)
{
    Arrete e;
    Graphe::m_aretes.insert(e)
    Graphe::aretes2Extremites.insert(std::make_pair(e, n1));
    Graphe::aretes2Extremites.insert(std::make_pair(e, n2));
    
}
    
Graphe::supprimerSommet( const Sommet &n)
{
    Graphe::m_sommets.erase(n);
    
}

Graphe::supprimerArete(const Arete &e)
{
    Graphe::m_aretes.erase(e);
}

std::set<Sommet> sommets()
{
    return Graphe::m_sommets
}

std::set<Arete> aretes()
{
    return Graphe::m_aretes
}

std::set<Sommet> voisins(const Sommet& n){
    std::set<Sommet> voisins;
    std::set<Arete> tmpAretes;
    for (auto it = aretes2Extremites.begin(); it != aretes2Extremites.end(); ++it) {
        if (it->second == n) {
            std::cout << "Key: " << it->first << std::endl;
            tmpAretes.insert(it->first);
        }
    }
    for (auto it = tmpAretes.begin(); it != tmpAretes.end(); ++it) {
        voisins.insert(Graphe::aretes2Extremites[it]);
    }

return voisins;

}
    /*std::set<Arete> incidentes(const Sommet& n) const;
    
    Sommet source(const Arete &e) const;
    Sommet destination(const Arete &e) const;
    int degre(const Sommet& n) const;
    int nbSommets() const;
    int nbAretes() const;*/
