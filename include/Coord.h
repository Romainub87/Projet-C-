#ifndef COORD_H
#define COORD_H

/// @brief
class Coord
{
private:
    /* data */
    float x;
    float y;

public:
    Coord();
    Coord(float x, float y);
    float norm() const;
    bool operator==(const Coord &c) const;
    Coord operator+(const Coord &c) const;
    Coord operator-(const Coord &c) const;
    Coord &operator+=(const Coord &c);
    Coord &operator-=(const Coord &c);
    Coord operator*(const float &f) const;
    Coord operator/(const float &f) const;
    Coord& operator*=(const float &f);
    Coord& operator/=(const float &f);
    float operator[](int dim) const;
    float& operator[](int dim);
    
    float getX() const;
    float getY() const;
    void setX(float x);
    void setY(float y);
    
};

#endif
