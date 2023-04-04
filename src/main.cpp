#include <iostream>
#include <deque>
#include <algorithm>
#include "Sommet.h"
#include "Graphe.h"
#include "Arete.h"
using namespace std;

const int LARGEUR = 1200;
const int HAUTEUR = 800;

int main(int argc, char *argv[])
{
    /*
    if (argc != 2){
        cout << "Usage: ./app <graph_file>.txt" << endl;
        return 1;
    }
    srand(time(NULL));

    // chargement et création des graphe et fenetre d'affichage
    string fichier (argv[1]);//"graphe.txt";//"fiat.txt"
    GrapheValue g;
    if(!g.charger(fichier)){
        cout << "Erreur de chargement de fichier" << endl;
        return 1;
    }

    Appli app {LARGEUR, HAUTEUR};
    app.setGraphe(g);

    // pour ne pas fermer la fenêtre après le dessin
    while(app.running())
        app.exec();

    return 0;
    */

    Graphe g;

    g.charger(argv[1]);

    // afficher nb d'aretes
    cout << "Nombre d'aretes : " << g.nbAretes() << endl;

    // afficher nb de sommets
    cout << "Nombre de sommets : " << g.nbSommets() << endl;
} 

