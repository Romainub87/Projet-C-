#include "Sommet.h"

using namespace std;

int Sommet::curr_id = 0;

/// @brief
/// @param valide
Sommet::Sommet(bool b)
{
    valide = b;
    id = Sommet::curr_id;
    Sommet::curr_id++;
}

int Sommet::getID() const
{
    return this->id;
}

bool Sommet::getValide() const
{
    return this->valide;
}

bool Sommet::operator==(const Sommet &autre) const
{
    return this->getID() == autre.getID();
}
