#include "Appli.h"
#include <iostream>
#include <fstream>
#include "GrapheValue.h"
#include "GrapheObserve.h"
using namespace std;

const float Appli::RAYON = 3;
const std::string Appli::FICHIER_FONT = "FreeSans.ttf";

Appli::Appli(unsigned int largeur, unsigned int hauteur) : m_mutex(PTHREAD_MUTEX_INITIALIZER)
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
    pthread_mutex_lock(&m_mutex);
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
            // transforme a.second en vertex

            sf::Vertex ligne[] = {
                sf::Vertex(sf::Vector2f(m_g->positionSommet(a.first.getOrigine()).getX(), m_g->positionSommet(a.first.getOrigine()).getY()), m_g->couleurSommet(a.first.getOrigine()).toSfColor()),
                sf::Vertex(sf::Vector2f(m_g->positionSommet(a.first.getDestination()).getX(), m_g->positionSommet(a.first.getDestination()).getY()), m_g->couleurSommet(a.first.getDestination()).toSfColor())};
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
    pthread_mutex_unlock(&m_mutex);
    m_fenetre.display();
}

void Appli::traiterAjout(const Sommet &n)
{
    creerFormeSommet(n);
}

void Appli::traiterAjout(const Arete &e)
{
    creerFormeArete(e);
}

void Appli::traiterSuppression(const Sommet &n)
{
    pthread_mutex_lock(&m_mutex);

    m_sommets.erase(n);

    pthread_mutex_unlock(&m_mutex);
}

void Appli::traiterSuppression(const Arete &e)
{
    pthread_mutex_lock(&m_mutex);

    m_aretes.erase(e);

    pthread_mutex_unlock(&m_mutex);
}

void Appli::traiterProprieteChangee(const Sommet &n)
{
    pthread_mutex_lock(&m_mutex);

    cout << "traiterProprieteChangee" << endl;
    cout << "est cre quelqu'un m'entend : " <<m_g->couleurSommet(n).getR() << endl;

    sf::CircleShape c(RAYON);
    c.setPosition(m_g->positionSommet(n).getX() - RAYON, m_g->positionSommet(n).getY() - RAYON);
        c.setOutlineColor(sf::Color::Black);
    c.setOutlineThickness(1);
    c.setFillColor(m_g->couleurSommet(n).toSfColor());
    m_sommets[n] = c;

    pthread_mutex_unlock(&m_mutex);
}

void Appli::traiterProprieteChangee(const Arete &e)
{
    pthread_mutex_lock(&m_mutex);

    sf::Vertex ligne[] = {
        sf::Vertex(sf::Vector2f(m_g->positionSommet(e.getOrigine()).getX(), m_g->positionSommet(e.getOrigine()).getY()), m_g->couleurArete(e).toSfColor()),
        sf::Vertex(sf::Vector2f(m_g->positionSommet(e.getDestination()).getX(), m_g->positionSommet(e.getDestination()).getY()), m_g->couleurArete(e).toSfColor())};
    m_aretes[e] = std::make_pair(ligne[0], ligne[1]);

    pthread_mutex_unlock(&m_mutex);
}

void Appli::creerFormeSommet(const Sommet &s)
{
    cout << s.getID() << endl;
    cout << "je suis arrivé" << endl;
    cout << m_g->positionSommet(s).getX() << endl;
    pthread_mutex_lock(&m_mutex);


    sf::CircleShape c(RAYON);
    c.setPosition(m_g->positionSommet(s).getX() - RAYON, m_g->positionSommet(s).getY() - RAYON);
    c.setOutlineColor(sf::Color::Black);
    c.setOutlineThickness(1);
    m_sommets.insert(std::make_pair(s, c));

    pthread_mutex_unlock(&m_mutex);
}

void Appli::creerFormeArete(Arete a)
{
    pthread_mutex_lock(&m_mutex);

    // couleur grise pour les aretes
    // creer les aeretes

    sf::Vertex ligne[] = {
        sf::Vertex(sf::Vector2f(m_g->positionSommet(a.getOrigine()).getX(), m_g->positionSommet(a.getOrigine()).getY()), m_g->couleurArete(a).toSfColor()),
        sf::Vertex(sf::Vector2f(m_g->positionSommet(a.getDestination()).getX(), m_g->positionSommet(a.getDestination()).getY()), m_g->couleurArete(a).toSfColor())};
    m_aretes.insert(std::make_pair(a, std::make_pair(ligne[0], ligne[1])));

    pthread_mutex_unlock(&m_mutex);
}

void Appli::calculerFormesGeometriques()
{
    Appli::dessiner();
}
