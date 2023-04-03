#include "Coord.h"
#include <cmath>
using namespace std;

Coord::Coord(float x, float y)
{
    abs = x;
    ord = y;
}

float Coord::norm() const
{
    return std::sqrt(std::pow(0 - abs, 2) + std::pow(0 - ord, 2));
}

bool Coord::operator==(const Coord &c) const
{
    return this->abs == c.abs && this->ord == c.ord;
}

Coord Coord::operator+(const Coord &c) const
{
    Coord tmp(this->abs + c.abs, this->ord + c.ord);
    return tmp;
}

Coord Coord::operator-(const Coord &c) const
{
    Coord tmp(this->abs - c.abs, this->ord - c.ord);
    return tmp;
}

Coord &Coord::operator+=(const Coord &c)
{
    Coord tmp(this->abs += c.abs, this->ord += c.ord);
    return tmp;
}

Coord &Coord::operator-=(const Coord &c)
{
    Coord tmp(this->abs -= c.abs, this->ord -= c.ord);
    return tmp;
}

Coord Coord::operator*(const float &f) const
{
    Coord tmp(this->abs * f, this->ord * f);
    return tmp;
}

Coord Coord::operator/(const float &f) const
{
    Coord tmp(this->abs / f, this->ord / f);
    return tmp;
}

Coord &Coord::operator*=(const float &f)
{
    Coord tmp(this->abs *= f, this->ord *= f);
    return tmp;
}

Coord &Coord::operator/=(const float &f)
{
    Coord tmp(this->abs /= f, this->ord /= f);
    return tmp;
}

float &Coord::operator[](int dim)
{
    return 0.0f;
}

float Coord::operator[](int dim) const
{
    Coord tmp(this->abs /= f, this->ord /= f);
    return tmp;
}

float Coord::operator[](int dim) const
{
    if(dim == 0){ return this->abs; }
    if(dim == 1) { return this->ord; }
    return 0.0f; // Valeur de retour par défaut
}

