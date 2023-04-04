#include "Graphe.h"
#include "utils.h"
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <fstream>
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

bool Graphe::charger(std::string fichier)
{
    map<int, Sommet> idSommet;

    // Ajout des sommets
    bool sommetsFinis = false;
    std::ifstream in(fichier.c_str());
    while (!in.eof())
    {
        char ligne[10000];
        in.getline(ligne, 10000);
        string lignes(ligne);
        lignes = lignes.substr(0, lignes.size() - 1);
        if (lignes == "#sommets")
        {
            continue;
        }
        else if (lignes == "#aretes")
        {
            sommetsFinis = true;
        }
        else if (!sommetsFinis)
        {
            int id = stoi(lignes);
            if (idSommet.find(id) != idSommet.end())
                return false; // deux fois le meme identifiant dans le fichier
            Sommet n = ajouterSommet();
            idSommet[id] = n;
        }
        else if (sommetsFinis && lignes != "")
        {
            vector<string> items;
            decouper(lignes, items, " ");
            if (items.size() != 2)
                return false;

            int id1 = stoi(items[0]);
            int id2 = stoi(items[1]);
            

            // test si les id sont corrects
            if (idSommet.find(id1) == idSommet.end() || idSommet.find(id2) == idSommet.end())
                return false;
            Sommet n1 = idSommet[id1];
            Sommet n2 = idSommet[id2];
            ajouterArete(n1, n2);
        }
    }
    return true;
}


