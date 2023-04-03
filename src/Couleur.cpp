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

Couleur Couleur::interpoler(const Couleur &c, float t) const
{
    int r = this->r + (c.r - this->r) * t;
    int g = this->g + (c.g - this->g) * t;
    int b = this->b + (c.b - this->b) * t;
    int alpha = this->alpha + (c.alpha - this->alpha) * t;
    return Couleur(r, g, b, alpha);
}

bool Couleur::operator==(const Couleur &c) const
{
    return this.r == c.r && this.g == c.g && this.b == c.b && this.alpha == c.alpha;
}
