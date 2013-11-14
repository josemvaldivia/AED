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
                cout<<*base<<endl;
                base++;
            }

        }
        STL to_function;
        typename STL::iterator base;
        int razon;

    protected:
    private:
};

#endif // FUNCTIONPRUEBA_H
