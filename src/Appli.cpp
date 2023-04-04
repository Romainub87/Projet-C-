#include "Appli.h"
#include <iostream>
#include <fstream>
#include "GrapheValue.h"

const float Appli::RAYON = 10;
const std::string Appli::FICHIER_FONT = "../fonts/FreeSans.ttf";

Appli::Appli(unsigned int largeur, unsigned int hauteur)
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
    m_sommet.setRadius(RAYON);
    m_sommet.setFillColor(sf::Color::White);
    m_sommet.setOutlineColor(sf::Color::Black);
    m_sommet.setOutlineThickness(2);
    m_montre_etiquette = false;
    m_interpoler_couleurs = false;
    m_g = nullptr;
}

void Appli::setGraphe(GrapheValue &g)
{
    m_g = &g;
}

bool Appli::running() const
{
    return m_fenetre.isOpen();
}

void Appli::exec()
{
    traiter_evenements();
    dessiner();
}

void Appli::traiter_evenements()
{
    sf::Event event;
    while (m_fenetre.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            m_fenetre.close();
            break;
        case sf::Event::KeyPressed:
            switch (event.key.code)
            {
            case sf::Keyboard::Escape:
                m_fenetre.close();
                break;
            case sf::Keyboard::E:
                m_montre_etiquette = !m_montre_etiquette;
                break;
            case sf::Keyboard::I:
                m_interpoler_couleurs = !m_interpoler_couleurs;
                break;
            default:
                break;
            }
            break;
        default:
            break;
        }
    }
}

void Appli::dessiner()
{
    m_fenetre.clear(sf::Color::White);
    if (m_g != nullptr)
    {

        // dessine les aretes du graphe
        for (auto a : m_g->aretes())
        {
            sf::Vertex ligne[] = {
                sf::Vertex(sf::Vector2f(a.getOrigine().getX(), a.getOrigine().getY()), m_g->couleurArete(a).toSfColor()),
                sf::Vertex(sf::Vector2f(a.getDestination().getX(), a.getDestination().getY()), m_g->couleurArete(a).toSfColor())};
            m_fenetre.draw(ligne, 2, sf::Lines);

            cout << a.getOrigine().getX() << " " << a.getOrigine().getY() << endl;
            cout << m_g->couleurArete(a).getR() << endl;
        }
        // dessine les sommets du graphe
        for (auto s : m_g->sommets())
        {
            m_sommet.setPosition(s.getX() - RAYON, s.getY() - RAYON);
            m_sommet.setFillColor(m_g->couleurSommet(s).toSfColor());
            m_fenetre.draw(m_sommet);
            if (m_montre_etiquette)
            {
                m_etiquette.setString(m_g->etiquetteSommet(s));
                m_etiquette.setPosition(s.getX(), s.getY());
                m_fenetre.draw(m_etiquette);
            }
        }
    }
    m_fenetre.display();
}