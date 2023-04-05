#include "ModeleDeForce.h"
#include <iostream>
#include "Coord.h"

ModeleDeForce::ModeleDeForce(GrapheValue *g)
{
    m_g = g;
};

void ModeleDeForce::initialiserDessin(unsigned int largeur, unsigned int hauteur)
{
    m_largeur = largeur;
    m_hauteur = hauteur;
    m_fenetre.create(sf::VideoMode(m_largeur, m_hauteur), "Graphe");
    m_vue.reset(sf::FloatRect(0, 0, m_largeur, m_hauteur));
    m_vue.setViewport(sf::FloatRect(0, 0, 1, 1));
    m_fenetre.setView(m_vue);
    m_font.loadFromFile(FICHIER_FONT);
    m_etiquette.setFont(m_font);
    m_etiquette.setCharacterSize(20);
    m_etiquette.setFillColor(sf::Color::Black);
    m_montre_etiquette = false;
    m_interpoler_couleurs = false;
    m_g = nullptr;
};

Coord ModeleDeForce::calculerAttractions(const Sommet &n)
{
    
}

Coord ModeleDeForce::calculerRepulsions(const Sommet &n)
{
   
}

Coord ModeleDeForce::calculerForces(const Sommet &n)
{
    
};

void ModeleDeForce::deplacer(const Sommet &n, Coord deplacement)
{
    n.position() += deplacement;
};

void ModeleDeForce::executer()
{
    for (const Sommet &n : m_g->sommets())
    {
        Coord force = calculerForce(n);
        deplacer(n, force);
    };
};
