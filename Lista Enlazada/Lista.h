#ifndef LISTA_H
#define LISTA_H
#include "nodo.h"
#include <iostream>
#include "asciende.h"
#include "desciende.h"
#include "traitasciende.h"
#include "traitdesciende.h"
using namespace std;

template <typename T>
class Lista
{
    public:
        Lista() {
            head = NULL;

        }
        virtual ~Lista() {
            Nodo<Tipo> * tmp;
            while (head!=NULL)
            {
                 tmp=head->showsig();
                 delete head;
                 head=tmp;

            }
        }
        typedef typename T:: MiT Tipo;
        typedef typename T:: Compara Comparar;
        Comparar Compa;
        bool insertar (Tipo x);
        bool encontrar (Tipo x, Nodo<Tipo> ** & p);
        bool borrar (Tipo datai);
        void imprimir();
    protected:

    private:
        Nodo<Tipo> * head;

};


template <typename T>
bool Lista<T>::encontrar (Tipo x, Nodo<Tipo> ** & p)
{
    for(p=&head;*p && Compa.comp((*p)->dato , x); p=&(*p)->sig);
    return *p && (*p)->dato==x;
}
template<typename T>
bool Lista <T>:: insertar (Tipo x)
{


    Nodo <Tipo> **tmp=&head;
    if(!encontrar(x,tmp))
    {

        Nodo<Tipo> *tmp2= *tmp;

        *tmp=new Nodo<Tipo>(x);
        (*tmp)->sig=tmp2;
        return true;

    }
    return false;
}

template <typename T>
bool Lista<T>:: borrar (Tipo datai)
{
    Nodo <Tipo>** pointer;
    if(encontrar(datai,pointer))
    {
        Nodo<Tipo>* tmp =*pointer;
        *pointer=(*pointer)->sig;
        delete tmp;
        return 1;
    }

    return 0;
}

template <typename T>
void Lista<T>::imprimir()
{
    Nodo<Tipo>**puntero=&head;
    while((*puntero)!=NULL)
    {

        cout<<(*puntero)->dato<<endl;
        puntero=&((*puntero)->sig);
    }
    cout<<"FIN LISTA\n\n\n\n";
}

#endif // LISTA_H
