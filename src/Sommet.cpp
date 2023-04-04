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

bool Sommet::operator<(const Sommet &autre) const
{
    return this->getID() < autre.getID();
}

float Sommet::operator[](int i) const
{
    if (i == 0)
    {
        return this->x;
    }
    else if (i == 1)
    {
        return this->y;
    }
    else
    {
        throw "Index out of bounds";
    }
}

float Sommet::getX() const
{
    return this->x;
}

float Sommet::getY() const
{
    return this->y;
}

void Sommet::setX(float x)
{
    this->x = x;
}

void Sommet::setY(float y)
{
    this->y = y;
}

void Sommet::setCouleur(Couleur c)
{
    this->couleur = c;
}

void Sommet::setEtiquette(std::string s)
{
    this->etiquette = s;
}

Couleur Sommet::getCouleur() const
{
    return this->couleur;
}

std::string Sommet::getEtiquette() const
{
    return this->etiquette;
}
