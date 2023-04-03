#include "Graphe.h"
#include <iostream>
#include <set>
using namespace std;

std::map<Arete, std::pair<Sommet, Sommet>> Graphe::aretes2Extremites;
std::map<Sommet, std::set<Arete>> Graphe::sommets2Incidentes;

int Graphe::nbAretes() const
{
    return 0;
}

Sommet Graphe::ajouterSommet()
{
    Sommet s;
    Graphe::m_sommets.insert(s);
    return s;
}

Arete Graphe::ajouterArete(const Sommet &n1, const Sommet &n2)
{
    Arete a;
    Graphe::m_aretes.insert(a);

    Graphe::aretes2Extremites.insert({a, std::make_pair(n1, n2)});

    if (Graphe::sommets2Incidentes.find(n1) == Graphe::sommets2Incidentes.end())
    {
        set<Arete> aretes;
        aretes.insert(a);
        Graphe::sommets2Incidentes[n1] = aretes;
    }
    else
    {
        Graphe::sommets2Incidentes[n1].insert(a);
    }

    if (Graphe::sommets2Incidentes.find(n2) == Graphe::sommets2Incidentes.end())
    {
        set<Arete> aretes;
        aretes.insert(a);
        Graphe::sommets2Incidentes[n2] = aretes;
    }
    else
    {
        Graphe::sommets2Incidentes[n2].insert(a);
    }

    return a;
}

