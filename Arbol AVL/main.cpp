#include <iostream>
#include "ArbolBinario.h"
#include "TraitMenor.h"
#include "TraitMayor.h"
using namespace std;

int main()
{

    ArbolBinario<TraitMenor<int> > a;
    a.insertar(10);
    a.insertar(11);
    a.insertar(14);
    a.insertar(12);
    a.insertar(15);
    a.insertar(18);
    a.insertar(20);
    a.inorder(a.cabeza);
    cout<<endl<<a.cabeza->dato;









    return 0;
}
