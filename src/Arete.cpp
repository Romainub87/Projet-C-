#include "Arete.h"
using namespace std;

int Arete::curr_id = 0;

Arete::Arete(bool b)
{
    valide = b;
    id = Arete::curr_id;
    Arete::curr_id++;
}

int Arete::getID() const
{
    return this->id;
}

bool Arete::getValide() const
{
    return this->valide;
}

bool Arete::operator==(const Arete &autre) const
{
    return this->getID() == autre.getID();
}

bool Arete::operator<(const Arete &autre) const
{
    return this->getID() < autre.getID();
}

Sommet Arete::operator[](int i) const
{
    if (i == 0)
    {
        return this->origine;
    }
    else if (i == 1)
    {
        return this->destination;
    }
    else
    {
        throw "Index out of bounds";
    }
}

Sommet Arete::getOrigine() const
{
    return this->origine;
}

Sommet Arete::getDestination() const
{
    return this->destination;
}

void Arete::setOrigine(Sommet s)
{
    this->origine = s;
}

void Arete::setDestination(Sommet s)
{
    this->destination = s;
}