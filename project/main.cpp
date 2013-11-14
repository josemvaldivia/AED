#include <iostream>
#include "TFor.h"
#include "DistributorDivision.h"
#include "FunctionPrueba.h"
#include <thread>
#include <vector>
#include <list>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main()
{
        srand(0);
        vector<int> lista;
        int x=0;
        for(int i=0;i<10;i++)
        {

            lista.push_back(x);
            x++;
        }

    	TFor< vector<int> ,FunctionPrueba< vector <int> > , DistributorDivision <vector< int > > > a(8,lista);


    return 0;
}
