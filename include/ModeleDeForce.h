#ifndef MODELEDEFORCE_H
#define MODELEDEFORCE_H

#include <SFML/Graphics.hpp>

class ModeleDeForce
{
private:
    /* data */
    GrapheValue *m_g;
public:
    ModeleDeForce() = delete;
    ModeleDeForce(GrapheValue *g);
    void initialiserDessin(unsigned int largeur, unsigned int hauteur);
    Coord calculerAttractions(const Sommet &v);
    Coord calculerRepulsions(const Sommet &v);
    Coord calculerForces(const Sommet &v);
    void deplacer(const Sommet &v, Coord deplacement);
    void executer();
};


#endif // MODELEDEFORCE_H
