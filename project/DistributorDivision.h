#ifndef DISTRIBUTORDIVISION_H
#define DISTRIBUTORDIVISION_H
#include <vector>
#include <iostream>
using namespace std;

/**< \class DistributorDivision

    Es el distribuidor con cargas iguales, este es un function object que distribuye la carga de los threads equitativamente, valiendose que el peso
    de cada uno es el mismo
*/

template <typename STL,typename FO>
class DistributorDivision
{
    public:

        typedef STL _STL/**<Estructura STL*/;
        typedef FO _FO;/**<Function Object*/

        DistributorDivision(int x, STL& a) {

            number_of_threads=x;
            stl_structure=a;

        }

         DistributorDivision() {


        }

        virtual ~DistributorDivision() {}
        vector< pair <typename STL::iterator, int> > operator () ()
        {
            /**<aqui se distribuira la carga y se enviara al TFor un vector de pares que segun el iterador y la razon podran mandarlo al FO*/
            vector< pair <typename STL::iterator, int> > result;
            int divi= stl_structure->size()/number_of_threads;
            int useful=0;
            int raz=0;
            for(typename STL::iterator i= (*stl_structure).begin(); i != (*stl_structure).end();i++)
            {

                if(result.size()==number_of_threads-1)
                {
                    pair <typename STL::iterator, int> tmp2;
                    tmp2.first=i;
                    tmp2.second=stl_structure->size()-(divi*(number_of_threads-1));
                    result.push_back(tmp2);
                    return result;

                }

                if(useful%divi==0)
                {

                    pair <typename STL::iterator, int> tmp2;
                    tmp2.first=i;
                    if (useful==0)tmp2.second=divi;
                    else tmp2.second=divi;
                    result.push_back(tmp2);
                }
                useful++;


            }


            return result;

        }
        bool type_dis=1;
        vector<vector<typename STL::iterator> > res;
        STL* stl_structure;
        int number_of_threads;
    protected:
    private:
};

#endif // DISTRIBUTORDIVISION_H
