#ifndef NODO_H
#define NODO_H
#include <iostream>
#include "Lista.h"
using namespace std;

template <class T>
class Nodo
{
    public:
        template <class A> friend class Lista;
        Nodo( T x) {

            dato=x;
            sig=NULL;
        }
        virtual ~Nodo() {


        }
        T showdato();
        Nodo<T> * showsig();
        void editdato(T dat);

    protected:
    private:
        T dato;
        Nodo<T> * sig;

};

template<typename T>
T Nodo<T>::showdato()
{

    return dato;
}

template<typename T>
Nodo<T>* Nodo<T>::showsig()
{

    return sig;
}
template <typename T>
void Nodo<T>:: editdato(T dat)
{
    dato=dat;
}

#endif // NODO_H
