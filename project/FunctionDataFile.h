#ifndef FUNCTIONDATAFILE_H
#define FUNCTIONDATAFILE_H
#define MAX_MOD 1000
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

                for(int i=0;i<=to_function->size();i+=razon)
                {
                   DoSomething(*base);
                   for(int a=0;a<razon;a++) base++;
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
        int razon;
        int num_of_threads;
    protected:
    private:


};

#endif // FUNCTIONDATAFILE_H
