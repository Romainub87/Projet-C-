#ifndef GRAPHVALUE_H
#define GRAPHVALUE_H

#include "Arete.h"
#include "Sommet.h"
#include "Graphe.h"
#include "Propriete.hpp"
#include "Couleur.h"
#include "Coord.h"


class GrapheValue: public Graphe
{
private:
    /* data */
    Propriete<Couleur> couleurs;
    Propriete<Coord> positions;
    Propriete<std::string> labels;
public:
    bool charger(std::string fichier) override;
    Sommet ajouterSommet() override;
    Arete ajouterArete(const Sommet &n1, const Sommet &n2) override;
    void supprimerSommet(const Sommet &n) override;
    void supprimerArete(const Arete &e) override;
    void positionSommet(Sommet n, Coord c);
    Coord positionSommet(Sommet n) const;
    void positionsMinMax(Coord &min, Coord &max);
    void couleurSommet(Sommet n, Couleur c);
    Couleur couleurSommet(Sommet n);
    void couleurArete(Arete e, Couleur c);
    Couleur couleurArete(Arete e);
    void etiquetteSommet(Sommet n, std::string s);
    std::string etiquetteSommet(Sommet n) const;
    void etiquetteArete(Arete e, std::string s);
    std::string etiquetteArete(Arete e) const;
    Propriete<Coord> getPositions() const;
};

#endif

