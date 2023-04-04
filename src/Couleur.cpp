#include "Couleur.h"



Couleur::Couleur()
{
    this->r = 0;
    this->g = 0;
    this->b = 0;
    this->alpha = 0;
}

Couleur::Couleur(int r, int g, int b, int alpha)
{
    this->r = r;
    this->g = g;
    this->b = b;
    this->alpha = alpha;
}

Couleur Couleur::interpoler(const Couleur &c, float t)
{
    int r = this->r + (c.r - this->r) * t;
    int g = this->g + (c.g - this->g) * t;
    int b = this->b + (c.b - this->b) * t;
    int alpha = this->alpha + (c.alpha - this->alpha) * t;
    return Couleur(r, g, b, alpha);
}

bool Couleur::operator==(const Couleur &c) const
{
    return this->r == c.r && this->g == c.g && this->b == c.b && this->alpha == c.alpha;
}

sf::Color Couleur::toSfColor() const
{
    return sf::Color(this->r, this->g, this->b, this->alpha);
}

const int &Couleur::operator[](int i) const
{
    switch (i)
    {
    case 0:
        return this->r;
    case 1:
        return this->g;
    case 2:
        return this->b;
    case 3:
        return this->alpha;
    default:
        return 0;
    }
}

int &Couleur::operator[](int i)
{
    switch (i)
    {
    case 0:
        return this->r;
    case 1:
        return this->g;
    case 2:
        return this->b;
    case 3:
        return this->alpha;
    default:
        return this->r;
    }
}