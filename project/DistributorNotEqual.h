#ifndef DISTRIBUTORNOTEQUAL_H
#define DISTRIBUTORNOTEQUAL_H
#include <vector>
#include <iostream>
using namespace std;
/**< \class DistributorNotEqual
    este distribuidor devolvera un vector de vectores que contienen al iterador al que se le aplicara la funcion en el function Object
    */
template <typename STL,typename FO>
class DistributorNotEqual
{

    public:

        typedef STL _STL;
        typedef FO _FO;

        DistributorNotEqual()
        {

        }

        DistributorNotEqual(int n, STL x) {
            stl_structure=x;
            number_of_threads=x;

        }
        virtual ~DistributorNotEqual() {

        }

        vector< pair <typename STL::iterator, int> > operator () ()
        {
            /**<devuelve un vector de pares para no generar conflicto en el TFor, pero este envia a result la distribucion que es posteriormente
            cargada en el TFor*/
            vector< pair <typename STL::iterator, int> > result;
            res.resize(number_of_threads);
            //stl_structure->sort();
            //Se comento la ordenacion ya que se torna demasiado lenta cuando se intenta ordenar una cantidad de datos grande
            int x=0;
            typename STL::iterator i=stl_structure->begin();
            for(i;i!=stl_structure->end();i++)
            {
                if(x%number_of_threads==0)x=0;
                res[x].push_back(i);
                x++;

            }

            return result;

        }
        bool type_dis =0;
        vector<vector<typename STL::iterator> > res;
        STL* stl_structure;
        int number_of_threads;
    protected:
    private:


};

#endif // DISTRIBUTORNOTEQUAL_H
