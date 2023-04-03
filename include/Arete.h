#ifndef ARETE_H
#define ARETE_H

/// @brief
class Arete
{
private:
    /* data */
    int id;
    bool valide;

public:
    /// @brief
    /// @param valide
    Arete(bool b = true);
    int getID() const;
    bool getValide() const;
    int static curr_id;
    bool operator==(const Arete &autre) const;
    bool operator<(const Arete &autre) const;
};

#endif
