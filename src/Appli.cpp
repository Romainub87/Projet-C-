#include "Appli.h"

using namespace std;

Appli::Appli(unsigned int largeur, unsigned int hauteur)
{
    m_largeur = largeur;
    m_hauteur = hauteur;
    m_fenetre.create(sf::VideoMode(m_largeur, m_hauteur), "Graphe");
    m_fenetre.setFramerateLimit(60);
    m_vue.reset(sf::FloatRect(0, 0, m_largeur, m_hauteur));
    m_vue.setViewport(sf::FloatRect(0, 0, 1, 1));
    m_fenetre.setView(m_vue);
    m_font.loadFromFile(FICHIER_FONT);
    m_etiquette.setFont(m_font);
    m_etiquette.setCharacterSize(20);
    m_etiquette.setColor(sf::Color::Black);
    m_sommet.setRadius(RAYON);
    m_sommet.setOrigin(RAYON, RAYON);
    m_sommet.setFillColor(sf::Color::White);
    m_sommet.setOutlineColor(sf::Color::Black);
    m_sommet.setOutlineThickness(1);
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
        if (event.type == sf::Event::Closed)
            m_fenetre.close();
        else if (event.type == sf::Event::KeyPressed)
        {
            if (event.key.code == sf::Keyboard::Escape)
                m_fenetre.close();
            else if (event.key.code == sf::Keyboard::E)
                m_montre_etiquette = !m_montre_etiquette;
            else if (event.key.code == sf::Keyboard::I)
                m_interpoler_couleurs = !m_interpoler_couleurs;
        }
    }
}

void Appli::dessiner()
{
    m_fenetre.clear(sf::Color::White);
    if (m_g != nullptr)
    {
        // dessiner les aretes
        for (auto a : m_g->aretes())
        {
            if (a.getValide())
            {
                sf::Vertex ligne[] =
                {
                    sf::Vertex(sf::Vector2f(a.getOrigine().getX(), a.getOrigine().getY())),
                    sf::Vertex(sf::Vector2f(a.getDestination().getX(), a.getDestination().getY()))
                };
                if (m_interpoler_couleurs)
                {
                    sf::Color c1 = a.getOrigine().getCouleur().toSfColor();
                    sf::Color c2 = a.getDestination().getCouleur().toSfColor();
                    sf::Color c = sf::Color((c1.r + c2.r) / 2, (c1.g + c2.g) / 2, (c1.b + c2.b) / 2);
                    ligne[0].color = c;
                    ligne[1].color = c;
                }
                else
                {
                    ligne[0].color = sf::Color::Black;
                    ligne[1].color = sf::Color::Black;
                }
                m_fenetre.draw(ligne, 2, sf::Lines);
            }
        }
        // dessiner les sommets
        for (auto s : m_g->sommets())
        {
            m_sommet.setPosition(s[0], s[1]);
            m_sommet.setFillColor(s.getCouleur().toSfColor());
            m_fenetre.draw(m_sommet);
            if (m_montre_etiquette)
            {
                m_etiquette.setString(to_string(s.getID()));
                m_etiquette.setPosition(s[0] + RAYON, s[1] + RAYON);
                m_fenetre.draw(m_etiquette);
            }
        }
    }
    m_fenetre.display();
}
