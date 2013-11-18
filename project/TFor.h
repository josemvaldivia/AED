/*Clase TFor.h (esqueleto)
Realizado por: Jose Manuel Valdivia Romero
*/

#ifndef TFOR_H
#define TFOR_H
#include <thread>
#include <vector>
#include <iostream>
#include "DistributorNotEqual.h"
#include "DistributorDivision.h"
#include "FunctionPrueba.h"
using namespace std;


template<typename STL /*tipo de estructura STL a utilizar (vector, lista, map, etc)*/,
typename FO /*function object que es la funcion en la que pondremos los threads*/,
typename D /*Distribuidor de Carga de los threads */>
class TFor
{
    public:
        TFor(int x,STL data) {
        	//al construirse con este "x" se especificara el numero de threads en total para realizar la funcion
        	data_structure=data;
			nthreads=x;
			thr= new thread[nthreads];
			Iterate();
		}

		TFor(STL data)					//Si construimos solo con el STL se asignara el numero de threads segun el hardware concurrency, es decir la cantidad de procesadores que tengamos
		{
            data_structure=data;
			nthreads=thread::hardware_concurrency();
			thr=new thread[nthreads];
			Iterate();

		}
        virtual ~TFor() {

            delete[] thr;

        }
        vector<pair<typename STL::iterator, int> > Distribute()
			{
				/*Aqui se desarrollara la funcion para distribuir la carga y devolvera un vector de vectores (la variable distributor), que contendra por cada thread el valor del iterador para que
				cada thread acceda a lo que tiene que mediante esto. Se usara el typename D (distribuidor de carga) para esto */
				distributor. number_of_threads= nthreads;
				distributor.stl_structure=data_structure;

				return distributor();

			}

		void Iterate()
		{
            /*en esta funcion se distribuiran las cargas de la thread con la funcion Distribute() y se soltaran las threads con el Function Object*/
            function_object.to_function= data_structure;
			distribution = Distribute();
			/*for(int i=0;i<nthreads;i++)
			{
                function_object.base=distribution[i].first;
                function_object.razon=distribution[i].second;
                thr[i]=thread(function_object);
			}*/


			int x=0;
			for(typename vector<pair<typename STL::iterator, int> >::iterator i = distribution.begin();i != distribution.end();i++)
			{
                function_object.base=(*i).first;
                function_object.razon=(*i).second;
                thr[x]=thread(function_object);
                x++;
			}
            Joining();

		}

		void Joining()
		{
			/*como la funcion Iterate lanzara las threads se usara la funcion join para esperar a todas las threads*/
			for (int i = 0; i < nthreads; ++i)
			{
				thr[i].join();
			}

		}

    protected:
    private:
    		STL data_structure;
    		thread * thr;
    		int nthreads;			// numero de threads que se usaran
    		vector<pair<typename STL::iterator, int> > distribution; // sera el que cargue toda la distribucion de los threads
    		D distributor;
    		FO function_object;
};

#endif // TFOR_H
