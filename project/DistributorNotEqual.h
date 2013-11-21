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
            res.reserve(number_of_threads);
            stl_structure->sort();
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
        vector<vector<typename STL::iterator> > res;
        STL* stl_structure;
        int number_of_threads;
    protected:
    private:


};

#endif // DISTRIBUTORNOTEQUAL_H
