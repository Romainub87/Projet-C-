#ifndef SOMMET_H
#define SOMMET_H

class Sommet
{
private:
 /* args */
 int id;
 bool valide;
public:
    Sommet(bool valide);
    int id() {
        return this->id;
    }
    bool valide() {
        return this->valide;
    }
};

#endif
