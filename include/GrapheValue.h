#ifndef GRAPHVALUE_H
#define GRAPHVALUE_H

#include "Arete.h"
#include "Sommet.h"
#include "Graphe.h"


class GrapheValue: public Graphe
{
private:
    /* data */
    Propriete<Couleur> couleurs;
    Propriete<Coord> positions;
    Propriete<std::string> labels;
public:
    bool charger(std::string fichier) override;
    Sommet ajouterSommet();
    Arete ajouterArete(const Sommet &n1, const Sommet &n2);
    void supprimerSommet(const Sommet &n);
    void supprimerArete(const Arete &e);
    void positionSommet(Sommet n, Coord c);
    Coord positionSommet(Sommet n);
    void positionsMinMax(Coord &min, Coord &max);
    void couleursSommet(Sommet n, Couleur c);
    Couleur couleursSommet(Sommet n);
    void couleursArete(Arete e, Couleur c);
    Couleur couleursArete(Arete e);
    void etiquettesSommet(Sommet n, std::string s);
    std::string etiquettesSommet(Sommet n) const;
    void etiquettesArete(Arete e, std::string s);
    std::string etiquettesArete(Arete e) const;
};

