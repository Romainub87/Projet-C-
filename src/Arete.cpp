#include "Arete.h"
using namespace std;

int Arete::curr_id = 0;

Arete::Arete(bool b)
{
    valide = b;
    id = Arete::curr_id;
    Arete::curr_id++;
}

int Arete::getID() const
{
    return this->id;
}

bool Arete::getValide() const
{
    return this->valide;
}
