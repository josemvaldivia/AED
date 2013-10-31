// ConsoleApplication5.cpp: define el punto de entrada de la aplicación de consola.

#include "stdafx.h"
#include <iostream>
#include "Matrix.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <thread>
#include <vector>

using namespace std;

void Search(int* result, CMatrix<char> & Mat, int i, int j)
{
    for(int a=0;a<10;a++)
    {
        result[a]=0;
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

vector<vector<int> > SearchAToJ(const CMatrix<char>& Mat)
{	
    vector<vector<int> > result;
    int nthreads = thread::hardware_concurrency();
	int div=Mat.matrix_m/nthreads;
	thread * thr = new thread[nthreads];
	int** tmp= new int*[nthreads];

	for(int i=0;i<nthreads;i++)
	{

		tmp[i]=new int [10];

	}


	for (int  i=0;i<nthreads-1;i++)
	{
		thr[i]=thread(Search,tmp[i],Mat,i*div,(i+1)*div-1);

	}

	thr[nthreads-1]=thread(Search,tmp[nthreads-1],Mat,(nthreads-1)*div,Mat.matrix_m-1);

	for(int i=0;i<nthreads;i++)
	{

		thr[i].join();

	}

	delete [] thr;
	for(int i=0;i<nthreads;i++)
	{

		delete [] tmp[i];

	}
	delete [] tmp;
	return result;

}

int _tmain(int argc, _TCHAR* argv[])
{
	srand((unsigned long)time(NULL));
    CMatrix<char> a  (20,20);
    a.FillWithCharacters();
    a.Show();
	vector<int> prueba;
	SearchAToJ(a);
	getchar();
	

    return 0;
}

