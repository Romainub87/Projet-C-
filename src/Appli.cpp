#include "Appli.h"
#include <iostream>
#include <fstream>
#include "GrapheValue.h"
#include "GrapheObserve.h"
using namespace std;

const float Appli::RAYON = 3;
const std::string Appli::FICHIER_FONT = "FreeSans.ttf";

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
    for (auto &a : m_aretes)
    {
        // transforme a.second en vertex
        sf::Vertex ligne[] = {
            a.second.first,
            a.second.second};
        m_fenetre.draw(ligne, 2, sf::Lines);
    }
    if (m_interpoler_couleurs)
    {
        for (auto &a : m_aretes)
        {
            cout << "Interpolation" << endl;
            // transforme a.second en vertex

            sf::Vertex ligne[] = {
                sf::Vertex(sf::Vector2f(a.first.getOrigine().getX(), a.first.getOrigine().getY()), a.first.getOrigine().getCouleur().toSfColor()),
                sf::Vertex(sf::Vector2f(a.first.getDestination().getX(), a.first.getDestination().getY()), a.first.getDestination().getCouleur().toSfColor())};
            m_aretes.insert(std::make_pair(a.first, std::make_pair(ligne[0], ligne[1])));
            m_fenetre.draw(ligne, 2, sf::Lines);
        }
    }
    for (auto &s : m_sommets)
    {
        m_fenetre.draw(s.second);
    }
    if (m_montre_etiquette)
    {
        for (auto &s : m_sommets)
        {
            m_etiquette.setString(std::to_string(s.first.getID()));
            m_etiquette.setPosition(s.second.getPosition().x + RAYON, s.second.getPosition().y + RAYON);
            m_fenetre.draw(m_etiquette);
        }
    }
    m_fenetre.display();
}

void Appli::traiterAjout(const Sommet &n)
{
    cout << "Ajout sommet " << n.getID() << endl;
    creerFormeSommet(n);
}

void Appli::traiterAjout(const Arete &e)
{
    cout << "Ajout arete " << e.getID() << endl;
    creerFormeArete(e);
}

void Appli::traiterSuppression(const Sommet &n)
{
    cout << "Suppression sommet " << n.getID() << endl;
    m_sommets.erase(n);
}

void Appli::traiterSuppression(const Arete &e)
{
    cout << "Suppression arete " << e.getID() << endl;
    m_aretes.erase(e);
}

void Appli::traiterProprieteChangee(const Sommet &n)
{
    cout << "Modification sommet " << n.getID() << endl;
    Appli::dessiner();
}

void Appli::traiterProprieteChangee(const Arete &e)
{
    cout << "Modification arete " << e.getID() << endl;
    Appli::dessiner();
}

void Appli::creerFormeSommet(const Sommet &s)
{
    sf::CircleShape c(RAYON);
    c.setPosition(s.getX() - RAYON, s.getY() - RAYON);
    cout << "Couleur sommet " << s.getCouleur().getR() << endl;
    c.setFillColor(s.getCouleur().toSfColor());
    c.setOutlineColor(sf::Color::Black);
    c.setOutlineThickness(1);
    m_sommets.insert(std::make_pair(s, c));
}

void Appli::creerFormeArete(Arete a)
{
    // couleur grise pour les aretes
    sf::Color couleur = Couleur(128, 128, 128, 50).toSfColor();
    // creer les aeretes

    sf::Vertex ligne[] = {
        sf::Vertex(sf::Vector2f(a.getOrigine().getX(), a.getOrigine().getY()), couleur),
        sf::Vertex(sf::Vector2f(a.getDestination().getX(), a.getDestination().getY()), couleur)};
    m_aretes.insert(std::make_pair(a, std::make_pair(ligne[0], ligne[1])));
}

void Appli::calculerFormesGeometriques()
{
    Appli::dessiner();
}
