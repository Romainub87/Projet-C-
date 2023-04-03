#include <iostream>
#include "Sommet.h"

using namespace std;

int main() {
    cout << "main" << endl;
    Sommet n;
    Sommet l;
    cout << n.getID() << endl;
    cout << l.getID() << endl;
    if (n == l)
    {
        std::cout << "Les sommets sont égaux." << std::endl;
    }
    else
    {
        std::cout << "Les sommets sont différents." << std::endl;
    }
}