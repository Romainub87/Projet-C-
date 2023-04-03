#include "Coord.h"
#include <cmath>
using namespace std;

Coord::Coord()
{
}

Coord::Coord(float x, float y)
{
    x = x;
    x = y;
}

float Coord::norm() const
{
    return std::sqrt(std::pow(0 - x, 2) + std::pow(0 - y, 2));
}

bool Coord::operator==(const Coord &c) const
{
    return this->x == c.x && this->y == c.y;
}

Coord Coord::operator+(const Coord &c) const
{
    Coord tmp(this->x + c.x, this->y + c.y);
    return tmp;
}

Coord Coord::operator-(const Coord &c) const
{
    Coord tmp(this->x - c.x, this->y - c.y);
    return tmp;
}

Coord &Coord::operator+=(const Coord &c)
{
    Coord tmp(this->x += c.x, this->y += c.y);
    return tmp;
}

Coord &Coord::operator-=(const Coord &c)
{
    Coord tmp(this->x -= c.x, this->y -= c.y);
    return tmp;
}

Coord Coord::operator*(const float &f) const
{
    Coord tmp(this->x * f, this->y * f);
    return tmp;
}

Coord Coord::operator/(const float &f) const
{
    Coord tmp(this->x / f, this->y / f);
    return tmp;
}

Coord &Coord::operator*=(const float &f)
{
    Coord tmp(this->x *= f, this->y *= f);
    return tmp;
}

Coord &Coord::operator/=(const float &f)
{
    Coord tmp(this->x /= f, this->y /= f);
    return tmp;
}

float Coord::operator[](int dim) const
{
    if (dim == 0)
        return x;
    else if (dim == 1)
        return y;
    else
        return 0.0f; // Valeur de retour par défaut
}

float &Coord::operator[](int dim)
{
    if (dim == 0)
        return x;
    else if (dim == 1)
        return y;
    else
        return x; // Valeur de retour par défaut
}
