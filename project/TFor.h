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
#include "FunctionDataFile.h"
using namespace std;


/**<
    \class TFor
    La clase TFor depende de un D, que es el distribuidor de carga, a este se carga la funcion con la respectiva clase STL, el TFor lanzara los threads
    segun lo que se indique, por defecto será el hardware_concurrency().

*/

template<typename D /*Distribuidor de Carga de los threads */>
class TFor
{
    public:

        typedef typename D::_STL STL;/**< STL es el tipo de dato STL al que se le aplicara la funcion*/
        typedef typename D::_FO FO;/**< FO es la funcion en un Function Object*/
        TFor(int x,STL data) {
        	//al construirse con este "x" se especificara el numero de threads en total para realizar la funcion
        	data_structure=data;
			nthreads=x;
			thr= new thread[nthreads];

		}

		TFor(STL data)					//Si construimos solo con el STL se asignara el numero de threads segun el hardware concurrency, es decir la cantidad de procesadores que tengamos
		{
            data_structure=data;
			nthreads=thread::hardware_concurrency();
			thr=new thread[nthreads];


		}
        virtual ~TFor() {

            delete [] thr;

        }

        vector< vector<typename STL::iterator > > Distribute2()
        {

            distributor. number_of_threads= nthreads;
			distributor.stl_structure=&data_structure;

			return distributor();

        }

        vector<pair<typename STL::iterator, int> > Distribute()
			{
				/**<Aqui se desarrollara la funcion para distribuir la carga y devolvera un vector de vectores (la variable distributor), que contendra por cada thread el valor del iterador para que
				cada thread acceda a lo que tiene que mediante esto. Se usara el typename D (distribuidor de carga) para esto */
				distributor. number_of_threads= nthreads;
				distributor.stl_structure=&data_structure;

				return distributor();

			}

		void operator () ()
		{
            /**<en esta funcion se distribuiran las cargas de la thread con la funcion Distribute() y se soltaran las threads
            con el Function Object*/
            function_object.to_function= &data_structure;
            typeofdist=distributor.type_dis;
            function_object.dist_type=typeofdist;
            function_object.num_of_threads=nthreads;
			distribution = Distribute();


            if(!distribution.empty())
            {
                int x=0;

                for(typename vector<pair<typename STL::iterator, int> >::iterator i = distribution.begin(); i != distribution.end() ; i++)
                {


                		function_object.base=(*i).first;
        	       		function_object.razon=(*i).second;
	               		thr[x%nthreads]=thread(function_object);
               			x++;

                }
			}

			else
			{

                function_object.not_equal=distributor.res;
                cout<<"SIZE\t"<<function_object.not_equal.size()<<endl;
                for(int i=0;i<nthreads;i++)
                {
                    function_object.razon=i;
                    thr[i]=thread(function_object);

                }
			}
            Joining();

		}

		void Joining()
		{
			/**<como la funcion Iterate lanzara las threads se usara la funcion join para esperar a todas las threads*/
			for (int i = 0; i < nthreads; ++i)
			{
				thr[i].join();
			}

		}

    protected:
    private:
            bool typeofdist; /**< El tipo de distribuidor, ira al Function Object para que este haga la funcion segun sea su tipo*/
    		STL data_structure;/**< es la estructura de datos contenida en el */
    		thread * thr;/**<El array de threads que se soltara*/
    		int nthreads;			/**<cantidad de threads que se utilizaran*/
    		vector<pair<typename STL::iterator, int> > distribution; /**< distribuidor cargado cuando la distribucion es pareja*/
            vector <vector <typename STL::iterator> > dit_not_eq;   /**< distribuidor cargado cuando la distribucion no es pareja*/
    		D distributor;  /**< la instancia del distribuidor*/
    		FO function_object; /**<La funcion que se aplicara a la estructura de datos*/
};

#endif // TFOR_H
