#include "GrapheObserve.h"
#include "Arete.h"
#include "Sommet.h"
#include "Graphe.h"
#include <iostream> 

// definition de la variable statique
std::set<ObservateurGraphe *> GrapheObserve::m_observateurs;

void GrapheObserve::notifierAjout(const Sommet &n)
{
    for (auto observateur : m_observateurs){
        observateur->traiterAjout(n);
    }
    
}

void GrapheObserve::notifierAjout(const Arete &e)
{
    for (auto observateur : m_observateurs)
        observateur->traiterAjout(e);
}

void GrapheObserve::notifierSuppression(const Arete &e)
{
    for (auto observateur : m_observateurs)
        observateur->traiterSuppression(e);
}

void GrapheObserve::notifierSuppression(const Sommet &n)
{
    for (auto observateur : m_observateurs)
        observateur->traiterSuppression(n);
}

void GrapheObserve::notifierProprieteChangee(const Sommet &n)
{
    for (auto observateur : m_observateurs)
        observateur->traiterProprieteChangee(n);
}

void GrapheObserve::notifierProprieteChangee(const Arete &e)
{
    for (auto observateur : m_observateurs)
        observateur->traiterProprieteChangee(e);
}

void GrapheObserve::attacher(ObservateurGraphe *observateur)
{
    cout << m_observateurs.size() << " observateur(s)" << endl;
    m_observateurs.insert(observateur);
    cout << m_observateurs.size() << " observateur(s)" << endl;
}

void GrapheObserve::detacher(ObservateurGraphe *observateur)
{
    m_observateurs.erase(observateur);
}

