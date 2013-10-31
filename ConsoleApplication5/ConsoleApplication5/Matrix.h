#ifndef CMATRIX_H
#define CMATRIX_H
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

template<typename T>
class CMatrix
{
    public:
        CMatrix(int m,int n)
        {
            matrix_m=m;
            matrix_n=n;
            data =new T*[m];
            data[0]= new T[m*n];
            for(int i=0;i<m;i++)
            {
                data[i]=data[0]+(n*i);
            }

        }

        virtual ~CMatrix()
        {
            delete [] data[0];
        }

        void FillWithCharacters();
        void Show();
        int matrix_m;
        int matrix_n;
        T** data;
    protected:
    private:


};

template<typename T>
void CMatrix<T>::FillWithCharacters()
{
    for(int i=0;i<matrix_m;i++)
    {
        for(int a=0;a<matrix_n;a++)
        {
         int tofill=rand()%26+97;
         data[i][a]=(T)tofill;

         }
    }
}

template<typename T>
void CMatrix<T>::Show()
{
    for(int i=0;i<this->matrix_m;i++)
    {
        for(int j=0;j<this->matrix_n;j++)
        {


        cout<<this->data[i][j]<<"  ";
        }
        cout<<"\n\n";
    }
}

#endif // CMATRIX_H
