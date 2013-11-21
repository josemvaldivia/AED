#ifndef FUNCTIONPRUEBA_H
#define FUNCTIONPRUEBA_H
#include <iostream>
#include <mutex>
using namespace std;
template<typename STL>
class FunctionPrueba
{


    public:

         typedef STL STL_;

        FunctionPrueba()
        {

        }

        FunctionPrueba(bool x) {

            dist_type=x;
        }
        virtual ~FunctionPrueba() {}

        void operator () ()
        {
            if(dist_type){
                for(int i=0;i<razon;i++)
                {
                    for(int i=0;i<=1000;i++)
                    {

                        for(int i=0;i<=1000;i++)
                        {
                            int x=rand()%653;
                            x+=rand()+*base;

                        }
                    }

                    base++;
                }
            }

            else
            {
                for(int i=*base;i<to_function->size();i+=i)
                {
                      for(int i=0;i<=1000;i++){

                        for(int i=0;i<=1000;i++)
                        {
                            int x=rand()%653;
                            x+=rand()+*base;

                        }
                    }

                }
            }


        }

        bool dist_type;
        STL* to_function;
        typename STL::iterator base;
        int razon;
        int num_of_threads;

    protected:
    private:
};

#endif // FUNCTIONPRUEBA_H
