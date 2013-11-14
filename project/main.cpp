#include <iostream>
#include "TFor.h"
#include "DistributorDivision.h"
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
        for(int i=0;i<100;i++)
        {
            int x=rand()%23;
            lista.push_back(x);
        }

    	TFor< list<int> ,char , DistributorDivision <list< int > > > a(8,lista);
    	a.Iterate();

    return 0;
}
