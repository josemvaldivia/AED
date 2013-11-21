#ifndef FUNCTIONDATAFILE_H
#define FUNCTIONDATAFILE_H
#include <iostream>
#include <vector>
#define MAX_MOD 1000
using namespace std;

/**< \class FunctionDataFile

Es un Function Object, este segun el tipo de distribucion hace que su razon haga distintos tipos de formacion, cuando es la distribucion
igual, se lanza con el primero, si no lanza al segundo que contiene al vector de vectores
*/

template <typename STL>
class FunctionDataFile
{


    public:

        typedef STL STL_;

        FunctionDataFile()
        {

        }


        virtual ~FunctionDataFile() {}

        void operator () ()
        {

            if(dist_type){
                for(int i=0;i<=razon;i++)
                {
                    DoSomething(*base);
                    base++;
                }

            }

            else
            {

                for(typename vector<typename STL::iterator> :: iterator i=not_equal[razon].begin();i!=not_equal[razon].end();i++)
                {
                    DoSomething(*(*i));
                }
            }


        }

        void DoSomething(int val){
            int sum = 0;
            for (int i=1; i <= val%MAX_MOD; i++){
                sum += val % i;
            }
        }

        bool dist_type;
        STL* to_function;
        typename STL::iterator base;
        vector< vector< typename STL::iterator> > not_equal;
        int razon;
        int num_of_threads;
    protected:
    private:


};

#endif // FUNCTIONDATAFILE_H
