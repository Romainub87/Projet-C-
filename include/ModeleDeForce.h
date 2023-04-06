#ifndef MODELEDEFORCE_H
#define MODELEDEFORCE_H
#include "Coord.h"
#include "Sommet.h"
#include <SFML/Graphics.hpp>
#include "GrapheValue.h"
#include <random>
class ModeleDeForce
{
private:
    /* data */
    GrapheValue *m_g;
    int m_hauteur;
    int m_largeur;

public:
    ModeleDeForce() = delete;
    ModeleDeForce(GrapheValue *g);
    void initialiserDessin(unsigned int largeur, unsigned int hauteur);
    Coord calculerAttractions(const Sommet &v);
    Coord calculerRepulsions(const Sommet &v);
    Coord calculerForces(const Sommet &v);
    void deplacer(const Sommet &v, Coord deplacement);
    void executer();
    Coord calculerForceGravite(const Sommet &n);
    int static maxDeplacement;
    static void *dessiner(void *vg);
};


#endif // MODELEDEFORCE_H
