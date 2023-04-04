#ifndef APPLI_H
#define APPLI_H
#include <SFML/Graphics.hpp>
#include "GrapheValue.h"

class Appli
{
public:
    Appli(unsigned int largeur, unsigned int hauteur);

    void setGraphe(GrapheValue &g);

    bool running() const;
    void exec();

private:
    sf::RenderWindow m_fenetre;
    sf::View m_vue;

    sf::Font m_font;

    sf::CircleShape m_sommet;
    sf::Text m_etiquette;
    GrapheValue *m_g;

    bool m_montre_etiquette;
    bool m_interpoler_couleurs;

    static const float RAYON;
    static const std::string FICHIER_FONT;

    unsigned int m_largeur, m_hauteur;

    void traiter_evenements();
    void dessiner();
};

#endif // APPLI_H
