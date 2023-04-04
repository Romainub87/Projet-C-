#ifndef PROPRIETE_H
#define PROPRIETE_H

#include "Arete.h"
#include "Sommet.h"
template <typename T>
class Propriete
{
private:
    std::map<Arete, T> m_aretes;
    std::map<Sommet, T> m_sommets;
public:
    void changer(const Sommet n, const T &valeur);
    void changer(const Arete e, const T &valeur);
    T get(const Sommet n) const;
    T get(const Arete e) const;
    void supprimer(const Sommet n);
    void supprimer(const Arete e);
};

template <typename T>
void Propriete<T>::changer(const Sommet n, const T &valeur)
{
    m_sommets[n] = valeur;
}

template <typename T>
void Propriete<T>::changer(const Arete e, const T &valeur)
{
    m_aretes[e] = valeur;
}

template <typename T>
T Propriete<T>::get(const Sommet n) const
{
    return m_sommets.at(n);
}

template <typename T>
T Propriete<T>::get(const Arete e) const
{
    return m_aretes.at(e);
}

template <typename T>
void Propriete<T>::supprimer(const Sommet n)
{
    m_sommets.erase(n);
}

template <typename T>
void Propriete<T>::supprimer(const Arete e)
{
    m_aretes.erase(e);
}

#endif
