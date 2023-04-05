// classe virtuelle pure
#ifndef OBSERVATEURGRAPHE_H
#define OBSERVATEURGRAPHE_H

#include "Arete.h"
#include "Sommet.h"

class ObservateurGraphe
{
public:
    virtual void traiterAjout(const Sommet &n) = 0;
    virtual void traiterAjout(const Arete &e) = 0;

    virtual void traiterSuppression(const Arete &e) = 0;
    virtual void traiterSuppression(const Sommet &n) = 0;

    virtual void traiterProprieteChangee(const Sommet &n) = 0;
    virtual void traiterProprieteChangee(const Arete &e) = 0;
};

#endif // OBSERVATEURGRAPHE_H