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
    // initialiser les positions des sommets aleatoirement en float avec real_distribution
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> disX(0, largeur);
    std::uniform_real_distribution<> disY(0, hauteur);
    for (Sommet s : m_g->sommets())
    {
        Coord c(disX(gen), disY(gen));
        m_g->positionSommet(s, c);
        m_g->notifierProprieteChangee(s);
    }

    for (Arete a : m_g->aretes())
    {
        m_g->notifierProprieteChangee(a);
    }

}


Coord ModeleDeForce::calculerAttractions(const Sommet &n)
{
    Coord coordV(m_g->positionSommet(n).getX(), m_g->positionSommet(n).getY());
    Coord sommeAttraction(0, 0);
    for (Sommet s : m_g->voisins(n))
    {

        Coord coordU(m_g->positionSommet(s).getX(), m_g->positionSommet(s).getY());
        cout << coordU.getX() << " " << coordU.getY() << endl;
        Coord vecteur = coordV - coordU;
        cout << vecteur.getX() << " " << vecteur.getY() << endl;
        float distance = vecteur.norm();
        sommeAttraction += vecteur * (distance*distance / 30);
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
        Coord vecteur = coordV - coordU;
        float distance = vecteur.norm();
        sommeRepultion += vecteur * (30/distance*distance*distance );
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
            
            m_g->positionSommet(som, m_g->positionSommet(n) + deplacement);
            
        }
        else
        {
            m_g->positionSommet(som, m_g->positionSommet(n));
        }
    }
    else
    {
        m_g->positionSommet(som, m_g->positionSommet(n));
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
        Coord c(m_g->positionSommet(s).getX(), m_g->positionSommet(s).getY());
        totalPosition += c;

    }
    Coord bary = totalPosition/nbSommet;
    Coord cV(m_g->positionSommet(n).getX(), m_g->positionSommet(n).getY());
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