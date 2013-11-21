#ifndef DISTRIBUTORNOTEQUAL_H
#define DISTRIBUTORNOTEQUAL_H
#include <vector>
#include <iostream>
using namespace std;

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
            vector< pair <typename STL::iterator, int> > result;
            stl_structure->sort();
            int x=0;
            typename STL::iterator i=stl_structure->begin();
            for(int a=0;a<number_of_threads;a++)
            {
                if(x%number_of_threads==0)x=0;
                pair<typename STL::iterator, int> tmp2;

                tmp2.first=i;
                tmp2.second=x;
                result.push_back(tmp2);
                x++;
                i++;
            }

            return result;

        }

        STL* stl_structure;
        int number_of_threads;
    protected:
    private:


};

#endif // DISTRIBUTORNOTEQUAL_H
