#include <iostream>
#include "Lista.h"
#include "nodo.h"
#include "traitasciende.h"
#include "traitdesciende.h"
using namespace std;

int main()
{
    Lista< TraitAsciende<int> > a;
    Lista <TraitDesciende <float> > b;
    a.insertar(4);
    a.insertar(1);
    a.insertar (2);
    a.insertar(43);
    a.insertar(20);
    a.insertar(1);
    a.imprimir();
    a.borrar(43);
    a.imprimir();

    b.insertar(3.4);
    b.insertar(2.1);
    b.insertar(6.4);
    b.imprimir();




    return 0;
}
