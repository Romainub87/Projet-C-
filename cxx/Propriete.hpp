#ifndef PROPRIETE_HPP
#define PROPRIETE_HPP

#include <map>
#include "Sommet.h"
#include "Arete.h"

template <typename T>
class Propriete
{
private:
    std::map<Sommet, T> m_sommetValues;
    std::map<Arete, T> m_areteValues;

public:
    void changer(Sommet n, const T &val);
    void changer(Arete e, const T &val);
    const T &valeur(Sommet n) const;
    const T &valeur(Arete e) const;
    void supprimer(Sommet n);
    void supprimer(Arete e);
};

template <typename T>
void Propriete<T>::changer(Sommet n, const T &val)
{
    m_sommetValues[n] = val;
}

template <typename T>
void Propriete<T>::changer(Arete e, const T &val)
{
    m_areteValues[e] = val;
}

template <typename T>
const T &Propriete<T>::valeur(Sommet n) const
{
    return m_sommetValues.at(n);
}

template <typename T>
const T &Propriete<T>::valeur(Arete e) const
{
    return m_areteValues.at(e);
}

template <typename T>
void Propriete<T>::supprimer(Sommet n)
{
    m_sommetValues.erase(n);
}

template <typename T>
void Propriete<T>::supprimer(Arete e)
{
    m_areteValues.erase(e);
}

#endif
