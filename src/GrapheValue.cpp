#include "GrapheValue.h"
#include "Couleur.h"
#include "Coord.h"
#include "Graphe.h"
#include "Sommet.h"
#include "Arete.h"
#include "Propriete.hpp"
#include "utils.h"
#include <fstream>
#include <iostream>
#include "GrapheObserve.h"

void GrapheValue::couleurArete(Arete e, Couleur c)
{
    couleurs.changer(e, c);
}

Couleur GrapheValue::couleurArete(Arete e)
{
    return couleurs.valeur(e);
}

void GrapheValue::etiquetteSommet(Sommet n, std::string s)
{
    labels.changer(n, s);
}

std::string GrapheValue::etiquetteSommet(Sommet n) const
{
    return labels.valeur(n);
}

void GrapheValue::etiquetteArete(Arete e, std::string s)
{
    labels.changer(e, s);
}

std::string GrapheValue::etiquetteArete(Arete e) const
{
    return labels.valeur(e);
}

void GrapheValue::positionSommet(Sommet n, Coord c)
{
    positions.changer(n, c);
}

Coord GrapheValue::positionSommet(Sommet n) const
{
    return positions.valeur(n);
}

Propriete<Coord> GrapheValue::getPositions() const
{
    return positions;
}

void GrapheValue::positionsMinMax(Coord &min, Coord &max)
{
    for (auto p : this->sommets())
    {
        if (p.getX() < min.getX())
            min.setX(p.getX());
        if (p.getY() < min.getY())
            min.setY(p.getY());
        if (p.getY() > max.getY())
            max.setX(p.getX());
        if (p.getY() > max.getY())
            max.setY(p.getY());
    }
}

void GrapheValue::couleurSommet(Sommet n, Couleur c)
{
    couleurs.changer(n, c);
}

Couleur GrapheValue::couleurSommet(Sommet n)
{
    return couleurs.valeur(n);
}

Arete GrapheValue::ajouterArete(const Sommet &n1, const Sommet &n2)
{
    Arete e = Graphe::ajouterArete(n1, n2);
    return e;
}

Sommet GrapheValue::ajouterSommet()
{
    Sommet n = Graphe::ajouterSommet();
    return n;
}

void GrapheValue::supprimerArete(const Arete &e)
{
    Graphe::supprimerArete(e);
    couleurs.supprimer(e);
    labels.supprimer(e);
}

void GrapheValue::supprimerSommet(const Sommet &n)
{
    Graphe::supprimerSommet(n);
    couleurs.supprimer(n);
    labels.supprimer(n);
    positions.supprimer(n);
}

bool GrapheValue::charger(std::string fichier)
{
    map<int, Sommet> idSommet;

    // Ajout des sommets
    bool sommetsFinis = false;
    std::ifstream in(fichier.c_str());
    while (!in.eof())
    {
        std::string ligne;
        std::getline(in, ligne);

        if (ligne == "#sommet;position;couleur;etiquette")
        {
            continue;
        }
        else if (ligne == "#aretes")
        {
            sommetsFinis = true;
        }
        else if (!sommetsFinis)
        {
            std::vector<std::string> items;
            decouper(ligne, items, ";");
            if (items.size() != 4)
                return false;

            int id = stoi(items[0]);

            std::vector<std::string> position;
            decouper(items[1], position, " ");
            Coord coord = Coord();
            coord.setX(stof(position[0]));
            coord.setY(stof(position[1]));

            std::vector<std::string> couleur;
            decouper(items[2], couleur, " ");
            Couleur color(stoi(couleur[0]), stoi(couleur[1]), stoi(couleur[2]), stoi(couleur[3]));
            std::string etiquette = items[3];

            if (idSommet.find(id) != idSommet.end())
                return false; // deux fois le meme identifiant dans le fichier
            Sommet n = ajouterSommet();
            n.setX(coord.getX());
            n.setY(coord.getY());
            n.setCouleur(color);
            etiquetteSommet(n, etiquette);
            notifierAjout(n);

            idSommet[id] = n;
        }
        else if (sommetsFinis && !ligne.empty())
        {
            std::vector<std::string> items;
            decouper(ligne, items, " ");
            if (items.size() != 2)
                return false;

            int id1 = stoi(items[0]);
            int id2 = stoi(items[1]);

            // test si les id sont corrects
            if (idSommet.find(id1) == idSommet.end() || idSommet.find(id2) == idSommet.end())
                return false;
            Sommet n1 = idSommet[id1];
            Sommet n2 = idSommet[id2];
            Arete a = ajouterArete(n1, n2);
            a.setOrigine(n1);
            a.setDestination(n2);
            etiquetteArete(a, "fairy tail > snk");
            couleurArete(a, Couleur(125, 125, 125, 50));
            notifierAjout(a);
        }
    }
    return true;
}

void GrapheValue::notifierAjout(const Sommet &n)
{

    GrapheObserve::notifierAjout(n);
    cout << "notifierAjoutSommet" << endl;
}

void GrapheValue::notifierAjout(const Arete &e)
{
    GrapheObserve::notifierAjout(e);
    cout << "notifierAjoutArete" << endl;
}

void GrapheValue::notifierSuppression(const Sommet &n)
{
    GrapheObserve::notifierSuppression(n);
}

void GrapheValue::notifierSuppression(const Arete &e)
{
    GrapheObserve::notifierSuppression(e);
}

void GrapheValue::notifierProprieteChangee(const Sommet &n)
{
    GrapheObserve::notifierProprieteChangee(n);
}

void GrapheValue::notifierProprieteChangee(const Arete &e)
{
    GrapheObserve::notifierProprieteChangee(e);
}

void GrapheValue::attacher(ObservateurGraphe *o)
{
    GrapheObserve::attacher(o);
}

void GrapheValue::detacher(ObservateurGraphe *o)
{
    GrapheObserve::detacher(o);
}
