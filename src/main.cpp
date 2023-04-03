#include <iostream>
#include "Sommet.h"

using namespace std;
#include "Arete.h"
#include "Graphe.h"

int main(int argc, char* argv[])
{
    /*
    cout << "main" << endl;

    Graphe g;

    Sommet n1 = g.ajouterSommet();
    Sommet n2 = g.ajouterSommet();
    Sommet n3 = g.ajouterSommet();
    Arete a1 = g.ajouterArete(n1, n2);
    Arete a2 = g.ajouterArete(n1, n3);

    cout << "nb sommets: " << g.nbSommets() << endl;
    cout << "nb aretes: " << g.nbAretes() << endl;

    cout << "sommets: " << endl;
    for (Sommet s : g.sommets())
    {
        cout << s.getID() << endl;
    }

    cout << "aretes: " << endl;
    for (Arete a : g.aretes())
    {
        cout << a.getID() << endl;
    }

    cout << "voisins de n1: " << endl;
    for (Sommet s : g.voisins(n1))
    {
        cout << s.getID() << endl;
    }

    cout << "incidentes de n1: " << endl;
    for (Arete a : g.incidentes(n1))
    {
        cout << a.getID() << endl;
    }

    cout << "source de a1: " << endl;
    cout << g.source(a1).getID() << endl;

    cout << "destination de a1: " << endl;
    cout << g.destination(a1).getID() << endl;

    cout << "degre de n1: " << endl;
    cout << g.degre(n1) << endl;

    g.supprimerArete(a1);
    cout << "nb aretes: " << g.nbAretes() << endl;

    g.supprimerSommet(n1);
    cout << "nb sommets: " << g.nbSommets() << endl;
    */

    Graphe g;

    // mettre l'argument 1 du terminal en parametres de la methode charger
    g.charger(argv[1]);

    cout << "nb sommets: " << g.nbSommets() << endl;
    cout << "nb aretes: " << g.nbAretes() << endl;
}
