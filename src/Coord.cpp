#include "Coord.h"
#include <cmath>
using namespace std;

Coord::Coord(float x, float y)
{
    x = x;
    y = y;
}

Coord::Coord()
{
    x = 0;
    y = 0;
}

float Coord::norm() const
{
    return sqrt(x * x + y * y);
}

bool Coord::operator==(const Coord &c) const
{
    return x == c.x && y == c.y;
}

Coord Coord::operator+(const Coord &c) const
{
    return Coord(x + c.x, y + c.y);
}

Coord Coord::operator-(const Coord &c) const
{
    return Coord(x - c.x, y - c.y);
}

Coord &Coord::operator+=(const Coord &c)
{
    x += c.x;
    y += c.y;
    return *this;
}

Coord &Coord::operator-=(const Coord &c)
{
    x -= c.x;
    y -= c.y;
    return *this;
}

Coord Coord::operator*(const float &f) const
{
    return Coord(x * f, y * f);
}

Coord Coord::operator/(const float &f) const
{
    return Coord(x / f, y / f);
}

Coord &Coord::operator*=(const float &f)
{
    x *= f;
    y *= f;
    return *this;
}

Coord &Coord::operator/=(const float &f)
{
    x /= f;
    y /= f;
    return *this;
}

float Coord::operator[](int dim) const
{
    if (dim == 0)
        return x;
    else if (dim == 1)
        return y;
    else
        return 0;
}

float &Coord::operator[](int dim)
{
    if (dim == 0)
        return x;
    else if (dim == 1)
        return y;
    else
        return x;
}

float Coord::getX() const
{
    return x;
}

float Coord::getY() const
{
    return y;
}

void Coord::setX(float x)
{
    x = x;
}

void Coord::setY(float y)
{
    y = y;
}
