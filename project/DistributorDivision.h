#ifndef DISTRIBUTORDIVISION_H
#define DISTRIBUTORDIVISION_H
#include <vector>
using namespace std;
template <typename STL>
class DistributorDivision
{
    public:

        DistributorDivision(int x, STL& a) {

            number_of_threads=x;
            stl_structure=a;

        }

         DistributorDivision() {

            number_of_threads=0;

        }

        virtual ~DistributorDivision() {}
        vector< pair <typename STL::iterator, int> > operator () ()
        {
            vector< pair <typename STL::iterator, int> > result;
            int divi= stl_structure.size()/number_of_threads;
            int useful=0;
            int raz=0;
            for(typename STL::iterator i= stl_structure.begin(); i != stl_structure.end();i++)
            {

                if(result.size()==number_of_threads-1)
                {
                    pair <typename STL::iterator, int> tmp2;
                    tmp2.first=i;
                    tmp2.second=stl_structure.size()-useful;
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
                    raz=0;
                }
                useful++;
                raz++;
            }

            return result;

        }
        STL stl_structure;
        int number_of_threads;
    protected:
    private:
};

#endif // DISTRIBUTORDIVISION_H
