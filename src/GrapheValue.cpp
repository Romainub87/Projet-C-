
#include "GrapheValue.h"


Couleur couleurSommet(Sommet s)
{
    return couleurs[s];
}

void couleurSommet(Sommet s, Couleur c)
{
    couleurs[s] = c;
}

void couleurArete(Arete a, Couleur c)
{
    couleurs[a] = c;
}

Couleur couleurArete(Arete a) const
{
    return couleurs[a];
}

void etiquetteSommet(Sommet s, std::string etiquette)
{
    labels[s] = etiquette;
}

std::string etiquetteSommet(Sommet s) const
{
    return labels[s];
}

void etiquetteArete(Arete a, std::string etiquette)
{
    labels[a] = etiquette;
}

std::string etiquetteArete(Arete a) const
{
    return labels[a];
}

Sommet GrapheValue::ajouterSommet()
{
    Sommet s = Graphe::ajouterSommet();
    couleurs[s] = Couleur::noir;
    positions[s] = Coord(0, 0);
    labels[s] = "";
    return s;
}

Arete GrapheValue::ajouterArete(const Sommet &s1, const Sommet &s2)
{
    Arete a = Graphe::ajouterArete(s1, s2);
    couleurs[a] = Couleur::noir;
    labels[a] = "";
    return a;
}

void GrapheValue::supprimerSommet(const Sommet &s)
{
    for (Arete a : incidentes(s))
        supprimerArete(a);
    couleurs.supprimer(s);
    positions.supprimer(s);
    labels.supprimer(s);
    Graphe::supprimerSommet(s);
}

void GrapheValue::supprimerArete(const Arete &a)
{
    couleurs.supprimer(a);
    labels.supprimer(a);
    Graphe::supprimerArete(a);
}

void GrapheValue::PositionSommet(Sommet s, Coord c)
{
    positions[s] = c;
}

Coord GrapheValue::PositionSommet(Sommet s) const
{
    return positions[s];
}

void GrapheValue::PositionMinMax(Coord &min, Coord &max)
{
    min = positions[0];
    max = positions[0];
    for (Sommet s : sommets())
    {
        if (positions[s].x < min.x)
            min.x = positions[s].x;
        if (positions[s].y < min.y)
            min.y = positions[s].y;
        if (positions[s].x > max.x)
            max.x = positions[s].x;
        if (positions[s].y > max.y)
            max.y = positions[s].y;
    }
}
