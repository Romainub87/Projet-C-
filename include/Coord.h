#ifndef COORD_H
#define COORD_H

/// @brief
class Coord
{
private:
    /* data */
    float abs;
    float ord;

public:
    Coord();
    Coord(float x, float y);
    float norm() const;
    bool operator==(const Coord &c) const ;
    Coord operator+(const Coord &c) const ;
    Coord operator-(const Coord &c) const ;
    Coord& operator+=(const Coord &c);
    Coord& operator-=(const Coord &c);
    Coord operator*(const float &f) const ;
    Coord operator/(const float &f) const;
    Coord& operator*=(const float &f);
    Coord& operator/=(const float &f);
};

#endif
