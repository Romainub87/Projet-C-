#ifndef ARETE_H;
#define ARETE_H;

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
    Arete(bool valide = true);
    int getID() const;
    bool getValide() const;
    int static curr_id;
};
