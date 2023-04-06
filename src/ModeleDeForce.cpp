#include "ModeleDeForce.h"
#include <iostream>
#include "Coord.h"
#include "GrapheValue.h"
#include "Sommet.h"
#include <random>
 #include <pthread.h>


int ModeleDeForce::maxDeplacement = 20;



ModeleDeForce::ModeleDeForce(GrapheValue *g)
{
    m_g = g;
}

void ModeleDeForce::initialiserDessin(unsigned int largeur, unsigned int hauteur)
{
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> distributionX(0, largeur);
    std::uniform_int_distribution<int> distributionY(0, hauteur);

    for (Sommet s : m_g->sommets()) {
        s.setX(distributionX(rng));
        s.setY(distributionY(rng));
    }
}


Coord ModeleDeForce::calculerAttractions(const Sommet &n)
{
    Coord coordV(n.getX(), n.getY());
    Coord sommeAttraction(0, 0);
    for (Sommet s : m_g->voisins(n))
    {

        Coord coordU(s.getX(), s.getY());
        cout << coordU.getX() << " " << coordU.getY() << endl;
        Coord vecteur = coordV - coordU;
        cout << vecteur.getX() << " " << vecteur.getY() << endl;
        float distance = vecteur.norm();
        sommeAttraction += vecteur * (distance / 30);
    }

    if (sommeAttraction.norm() > 300)
    {
        sommeAttraction /= sommeAttraction.norm(); // vecteur unitaire
        sommeAttraction *= 300;                    // vecteur de norme MAX_ATTRACTIVE
    }
    return sommeAttraction;
}

Coord ModeleDeForce::calculerRepulsions(const Sommet &n)
{
    Coord coordV(n.getX(), n.getY());
    Coord sommeRepultion(0, 0);
    Coord zero(0, 0);
    for (Sommet s : m_g->sommets())
    {

        Coord coordU(s.getX(), s.getY());
        Coord vecteur = coordU - coordV;
        float distance = vecteur.norm();
        sommeRepultion += vecteur * (distance / 30);
    }

    if (sommeRepultion.norm() > 60)
    {
        sommeRepultion /= sommeRepultion.norm(); // vecteur unitaire
        sommeRepultion *= 60;                    // vecteur de norme MAX_ATTRACTIVE
    }
    return sommeRepultion;
}

Coord ModeleDeForce::calculerForces(const Sommet &n)
{
    Coord forceAttraction = calculerAttractions(n);
    Coord forceRepulstion = calculerRepulsions(n);
    return forceAttraction + forceRepulstion;
}

void ModeleDeForce::deplacer(const Sommet &n, Coord deplacement)
{
    Sommet& som = const_cast<Sommet&>(n);
    float depX = deplacement.getX();
    float depY = deplacement.getY();
    if (depX < maxDeplacement)
    {
        if (depY < maxDeplacement)
        {
            
            som.setX(n.getX() + depX);
            som.setY(n.getY() + depY);
            
        }
        else
        {
            som.setX(n.getX());
            som.setY(n.getY());
        }
    }
    else
    {
        som.setX(n.getX());
        som.setY(n.getY());
    }
    maxDeplacement = maxDeplacement - 1;
}

void ModeleDeForce::executer()
{
    this->initialiserDessin(1200, 800);
    for(int i = 0; i<1000; i++){
        for(Sommet v : m_g->sommets()){
            this->calculerForces(v);
            this->deplacer(v, this->calculerForceGravite(v));
        }

    }
}

Coord ModeleDeForce::calculerForceGravite(const Sommet &n)
{
    int nbSommet = m_g->nbSommets();
    Coord totalPosition(0,0);
    for(Sommet s : m_g->sommets()){
        Coord c(s.getX(), s.getY());
        totalPosition += c;

    }
    Coord bary = totalPosition/nbSommet;
    Coord cV(n.getX(), n.getY());
    return (bary-cV)*0.1f;
}


void* ModeleDeForce::dessiner(void *vg)
{
    GrapheValue * gV = (GrapheValue *) vg;
    
    ModeleDeForce md(gV);
    md.executer();
    return nullptr;

    pthread_exit(0);
}