#include <iostream>
#include <deque>
#include <algorithm>
#include "Sommet.h"
#include "Graphe.h"
#include "GrapheValue.h"
#include "Appli.h"
#include "Arete.h"
#include "GrapheObserve.h"
using namespace std;

const int LARGEUR = 1200;
const int HAUTEUR = 800;

int main(int argc, char *argv[])
{
    

    if (argc != 2){
        cout << "Usage: ./app <graph_file>.txt" << endl;
        return 1;
    }
    srand(time(NULL));

    // chargement et création des graphe et fenetre d'affichage
    string fichier (argv[1]);//"graphe.txt";//"fiat.txt"
    GrapheValue g;

    Appli app {LARGEUR, HAUTEUR};
    g.attacher(&app);

     if (!g.charger(fichier))
    {
        cout << "Erreur de chargement de fichier" << endl;
        return 1;
    }

    // affiche nb de sommet de g
    cout << "Nombre de sommets : " << g.nbSommets() << endl;

    // affiche nb d'aretes de g
    cout << "Nombre d'aretes : " << g.nbAretes() << endl;

    // pour ne pas fermer la fenêtre après le dessin
    while(app.running())
        app.exec();

    return 0;
} 

