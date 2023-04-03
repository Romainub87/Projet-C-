#include "Graphe.h"
#include <iostream>
#include <set>
using namespace std;

std::map<Arete, std::pair<Sommet, Sommet>> Graphe::aretes2Extremites;
std::map<Sommet, std::set<Arete>> Graphe::sommets2Incidentes;

int Graphe::nbAretes() const
{
    return m_aretes.size();
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

int Graphe::nbSommets() const
{
    return m_sommets.size();
}

std::set<Sommet> Graphe::sommets() const
{
    return Graphe::m_sommets;
}

std::set<Arete> Graphe::aretes() const
{
    return Graphe::m_aretes;
}

std::set<Sommet> Graphe::voisins(const Sommet &n) const
{
    set<Sommet> voisins;
    for (auto arete : Graphe::sommets2Incidentes.at(n))
    {
        auto extremites = Graphe::aretes2Extremites.at(arete);
        if (extremites.first == n)
        {
            voisins.insert(extremites.second);
        }
        else
        {
            voisins.insert(extremites.first);
        }
    }
    return voisins;
}

std::set<Arete> Graphe::incidentes(const Sommet &n) const
{
    return Graphe::sommets2Incidentes.at(n);
}

Sommet Graphe::source(const Arete &e) const
{
    return Graphe::aretes2Extremites.at(e).first;
}

Sommet Graphe::destination(const Arete &e) const
{
    return Graphe::aretes2Extremites.at(e).second;
}

int Graphe::degre(const Sommet &n) const
{
    return Graphe::sommets2Incidentes.at(n).size();
}

void Graphe::supprimerSommet(const Sommet &n)
{
    Graphe::m_sommets.erase(n);
    for (auto arete : Graphe::sommets2Incidentes.at(n))
    {
        Graphe::m_aretes.erase(arete);
        Graphe::aretes2Extremites.erase(arete);
    }
    Graphe::sommets2Incidentes.erase(n);
}

void Graphe::supprimerArete(const Arete &e)
{
    Graphe::m_aretes.erase(e);
    Graphe::aretes2Extremites.erase(e);
    for (auto sommet : Graphe::sommets2Incidentes)
    {
        sommet.second.erase(e);
    }
}


