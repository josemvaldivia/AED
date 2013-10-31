#include <iostream>
#include "arbolbinario.h"
#include "nodo.h"
using namespace std;

int main()
{
    ArbolBinario<TraitMayor<int> > a;
    a.insertar(5);
    a.insertar(3);
    a.insertar(2);
    a.insertar(7);
    a.insertar(8);
    a.insertar(1);





    return 0;
}
