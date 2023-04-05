 #ifndef GRAPHEOBSERVE_H
 #define GRAPHEOBSERVE_H

#include "ObservateurGraphe.h"
#include "Arete.h"
#include "Sommet.h"
#include <set>
 

class GrapheObserve
{
protected:
    static std::set<ObservateurGraphe *> m_observateurs;

    virtual void notifierAjout(const Sommet &n);
    virtual void notifierAjout(const Arete &e);

    virtual void notifierSuppression(const Arete &e);
    virtual void notifierSuppression(const Sommet &n);

    virtual void notifierProprieteChangee(const Sommet &n);
    virtual void notifierProprieteChangee(const Arete &e);

public:
    GrapheObserve() = default;
    virtual ~GrapheObserve() = default;

    virtual void attacher(ObservateurGraphe *observateur);
    virtual void detacher(ObservateurGraphe *observateur);
};

#endif // GRAPHEOBSERVE_H