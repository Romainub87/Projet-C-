
#include "Graphe.h"
#include "Coord.h"
#include "Propriete.hpp"
#include "Couleur.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <set>
#include <map>

#ifndef GRAPHEVALUE_H
#define GRAPHEVALUE_H

class GrapheValue : public Graphe
{
private:
    Propriete<Couleur> couleurs;
    Propriete<Coord> positions;
    Propriete<std::string> labels;

public:
    bool charger(std::string fichier) override;
    Sommet ajouterSommet();
    Arete ajouterArete(const Sommet &s1, const Sommet &s2);
    void supprimerSommet(const Sommet &s);
    void supprimerArete(const Arete &a);
    void PositionSommet(Sommet s, Coord c);
    Coord PositionSommet(Sommet s) const;
    void PositionMinMax(Coord &min, Coord &max);
    void couleurSommet(Sommet s, Couleur c);
    Couleur couleurSommet(Sommet s);
    void couleurArete(Arete a, Couleur c);
    Couleur couleurArete(Arete a) const;
    void etiquetteSommet(Sommet s, std::string etiquette);
    std::string etiquetteSommet(Sommet s) const;
    void etiquetteArete(Arete a, std::string etiquette);
    std::string etiquetteArete(Arete a) const;
};

#endif // GRAPHEVALUE_H
