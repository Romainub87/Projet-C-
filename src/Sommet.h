
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
    Sommet(bool valide = true);
    int getID() const;
    bool getValide() const;
};

#endif
