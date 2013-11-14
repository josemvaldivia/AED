#include "cmatrix.h"
#include <thread>
#include <iostream>
#include <vector>
#include <sched.h>
using namespace std;


void Search(vector<int> & result, CMatrix<char> & Mat, int i, int j)
{
    for(int a=0;a<10;a++)
    {
        result.push_back(0);
    }

    for(i;i<j;i++)
    {
        for(int a=0;a<Mat.matrix_n;a++)
        {
            for(int x =(int)'a';x<=(int)'j';x++ )
            {
                if((char)x==Mat.data[i][a])
                {
                cout<<"se aumenta\t"<<Mat.data[i][a]<<endl;
                result[((int)Mat.data[i][a]+3)%10]++;
                }
            }

        }
    }
}

vector<vector<int> > SearchAToJ(CMatrix<char>& Mat)
{
        vector<vector<int> > result;
        int nthreads = thread::hardware_concurrency();
        int div=Mat.matrix_m/nthreads;
        thread * thr = new thread[nthreads];
        vector<int>* tmp=new vector<int> [nthreads];

        for(int i=0;i<nthreads;i++)
        {
            tmp[i].reserve(10);
        }

        vector<int> temporal;
        int i=0;




    /*
        for(int i=0;i<nthreads;i++)
        {

                thr[i].join();

      */

        delete [] thr;
        delete [] tmp;
        return result;

}

int main()
{
    srand((unsigned long)time(NULL));
    CMatrix<char> a (20,20);
    a.FillWithCharacters();
    a.Show();
    vector<int> temporal;
    thread  F1(Search,temporal,a,0,2);
    vector<int> as;
    Search(as,a,7,10);



    return 0;
}

