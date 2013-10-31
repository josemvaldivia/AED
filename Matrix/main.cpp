#include <iostream>
#include "cmatrix.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <thread>
#include <vector>

using namespace std;

vector<int> Search(const CMatrix<char> & Mat, int i, int j)
{

    vector<int> result;

    for(int i=0;i<10;i++)
    {
        result.push_back(0);
    }

    for(i;i<j;i++)
    {
        for(int a=0;a<Mat.matrix_n;a++)
        {
            for(int x =(int)'a';x<(int)'j';x++ )
            {
                if((char)x==Mat.data[i][a])
                {

                result[(x+3)%10]++;
                }
            }

        }
    }
}

vector<vector<int> > SearchAToJ(const CMatrix<char>& Mat)
{
    //thread * a;
    int nthreads = thread::hardware_concurrency();


}

int main()
{
    srand(time(NULL));
    CMatrix<char> a  (20,20);

    a.FillWithCharacters();
    a.Show();
    return 0;
}
