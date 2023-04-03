
#ifndef SOMMET_H
#define SOMMET_H

/// @brief 
class Sommet
{
private:
 /* args */
 int id;
 bool valide;
public:
    /// @brief 
    /// @param valide 
    Sommet(bool b = true);
    int getID() const;
    bool getValide() const;
    int static curr_id;
    bool operator==(const Sommet &autre) const;
    bool operator<(const Sommet &autre) const;
};

#endif
