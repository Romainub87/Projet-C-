#ifndef ARETE_H
#define ARETE_H

#include "Sommet.h"
/// @brief
class Arete
{
private:
    /* data */
    Sommet origine;
    Sommet destination;
    int id;
    bool valide;

public:
    /// @brief
    /// @param valide
    Arete(bool b = true);
    int getID() const;
    bool getValide() const;
    int static curr_id;
    bool operator==(const Arete &autre) const;
    bool operator<(const Arete &autre) const;
    Sommet operator[](int i) const;
    Sommet getOrigine() const;
    Sommet getDestination() const;
};

#endif
