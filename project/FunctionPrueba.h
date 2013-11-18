#ifndef FUNCTIONPRUEBA_H
#define FUNCTIONPRUEBA_H
#include <iostream>
#include <mutex>
using namespace std;
template<typename STL>
class FunctionPrueba
{
    public:

        FunctionPrueba() {

        }
        virtual ~FunctionPrueba() {}

        void operator () ()
        {
            for(int i=0;i<razon;i++)
            {

                for(int i=0;i<1000;i++)
                {
                int x=rand()%653;
                cout<<*base*x%433<<endl;
                base++;
                1+1+1+1+1+1+1+1+1+1+1+1;
                }
            }

        }
        STL to_function;
        typename STL::iterator base;
        int razon;

    protected:
    private:
};

#endif // FUNCTIONPRUEBA_H
