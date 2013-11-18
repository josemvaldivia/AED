#ifndef DISTRIBUTORNOTEQUAL_H
#define DISTRIBUTORNOTEQUAL_H
#include <vector>

using namespace std;

template <typename STL>
class DistributorNotEqual
{
    public:

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
            stl_structure.sort();

            for(typename STL::iterator i=stl_structure.begin();i!=stl_structure.end();i++)
            {
                pair<typename STL::iterator, int> tmp2;

                tmp2.first=i;
                tmp2.second=0;

                result.push_back(tmp2);
            }

        }

        STL stl_structure;
        int number_of_threads;
    protected:
    private:


};

#endif // DISTRIBUTORNOTEQUAL_H
