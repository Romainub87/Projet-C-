
#ifndef SOMMET_H
#define SOMMET_H

#include "Couleur.h"
using namespace std;
#include <string>

/// @brief
class Sommet
{
private:
    /* args */
    Couleur couleur;
    std::string etiquette;
    float x;
    float y;
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
    float operator[](int i) const;
    float getX() const;
    float getY() const;
    void setX(float x);
    void setY(float y);
    void setCouleur(Couleur c);
    void setEtiquette(std::string s);
    Couleur getCouleur() const;
    std::string getEtiquette() const;
};

#endif
