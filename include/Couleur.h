#ifndef COULEUR_H
#define COULEUR_H
class Couleur
{
private:
    /* data */
    int r;
    int g;
    int b;
    int alpha;
public:
    Couleur();
    Couleur(int r, int g, int b, int alpha);
    Couleur interpoler(const Couleur &c, float t);
    bool operator==(const Couleur &c) const;
    
};

#endif
