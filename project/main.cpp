#include <iostream>
#include "TFor.h"
#include <thread>
#include <vector>
#include <list>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main()
{
        srand(0);
        list<int> lista;
        int x=0;
        for(int i=0;i<100;i++)
        {

            lista.push_back(x);
            x++;
        }

    	TFor<DistributorDivision <list<int>,FunctionPrueba<list<int> > > > a(lista) ;
    	a();

    return 0;
}
