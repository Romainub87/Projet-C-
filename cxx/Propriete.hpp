
#ifndef PROPRIETE_HPP
#define PROPRIETE_HPP

#include <map>
template <typename T>
class Propriete
{
public:
    void changer(Sommet s, const T &valeur);
    void changer(Arete a, const T &valeur);
    const T &valeur(Sommet s) const;
    const T &valeur(Arete a) const;
    void supprimer(Sommet s);
    void supprimer(Arete a);

private:
    std::map<Sommet, T> m_sommets;
    std::map<Arete, T> m_aretes;
};

#endif

