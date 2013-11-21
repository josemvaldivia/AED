#include <iostream>
#include "TFor.h"
#include <thread>
#include <vector>
#include <list>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include "FunctionDataFile.h"
using namespace std;


int main()
{


    /**<Aplication TFor, este es un "for" personalizado que reparte cargas a los threads indicados para poder acelerar el proceso */

    ifstream fin("data.dat");
    list<int> data;
    int i=0;
    while(!fin.eof()){
        int val;
        fin>>val;
        data.push_back(val);
        i++;
    }


    cout<<"data loaded\t"<<i<<"\t"<<endl;

    /*
        srand(0);
        list<int> lista;
        int x=0;
        for(int i=0;i<100;i++)
        {

            lista.push_back(x);
            x++;
        }
*/
    TFor<DistributorNotEqual<list<int>,FunctionDataFile<list<int> > > > a(data) ;
    a();
    cout<<"finished"<<endl;
    return 0;

}
