#include "Sommet.h"

using namespace std;

int lastId = 1;

/// @brief 
/// @param valide 
Sommet::Sommet(bool valide)
{
    this->valide = valide;
    this->id = lastId;
    lastId++;   
}

int Sommet::getID() const
{
    return this->id;
}

bool Sommet::getValide() const
{
    return this->valide;
}
