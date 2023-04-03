#include <iostream>
#include "Sommet.h"

using namespace std;
#include "Arete.h"
#include "Graphe.h"

int main()
{
    cout << "main" << endl;

    Graphe g;

    Sommet n1 = g.ajouterSommet();
    Sommet n2 = g.ajouterSommet();
    Sommet n3 = g.ajouterSommet();
    Arete a1 = g.ajouterArete(n1, n2);
    Arete a2 = g.ajouterArete(n1, n3);

    cout << a1.getID() << endl;
    cout << a2.getID() << endl;

    cout << n1.getID() << endl;
    cout << n2.getID() << endl;
}
