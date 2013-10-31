#ifndef ARBOLBINARIO_H
#define ARBOLBINARIO_H
#include "nodo.h"
#include "traitmayor.h"
#include <iostream>

using namespace std;

template <typename Tr>
class ArbolBinario
{
    public:
        typedef typename Tr::Tipo TipoT;
        typedef typename Tr::C Comparacion;
        typedef Nodo<TipoT>** Nod;
        Nodo<TipoT> * cabeza;
        Comparacion Compa;

        ArbolBinario() {
        cabeza=NULL;
        }

        virtual ~ArbolBinario() {}
        bool buscar (TipoT d, Nodo<TipoT> ** &p);
        bool insertar (TipoT d);
        bool eliminar (TipoT n);
        Nodo <TipoT>** remplazo (Nodo<TipoT>** p);
        void inorder (Nodo<TipoT>* t);
    protected:
    private:
};

template<typename T>
void ArbolBinario<T>::inorder(Nodo<TipoT>* t)
{
    if(!t) {return;}
    inorder(t->rama[0]);
    cout<<t->dato;
    inorder(t->rama[1]);

}

template<typename T>
typename ArbolBinario<T>::Nod ArbolBinario<T>::remplazo(Nodo<TipoT>** p)
{

    p=&cabeza;
    (*p)=(*p)->rama[0];
    while((*p)->rama[1]!=NULL)
    {

        (*p)=(*p)->rama[1];

    }

    return p;

}

template<typename Tr>
bool ArbolBinario<Tr>::buscar(TipoT d, Nodo <TipoT> ** & p)
{

    for(p=&cabeza;*p;p=&(*p)->rama[Compa((*p)->dato,d)])
    {

        if ((*p)->dato==d)
        {
            return 1;
        }

    }

    return 0;
}

template <typename Tr>
bool ArbolBinario<Tr>::insertar (TipoT d)
{

    Nodo<TipoT> **p;
    if (!buscar(d,p))
    {
        *p=new Nodo<TipoT>(d);
        return true;
    }
    return false;

}

template <typename Tr>
bool ArbolBinario<Tr>::eliminar (TipoT n)
{
    Nodo<TipoT>** p;
    Nodo<TipoT>** q;
    p=&cabeza;
    if (!buscar(n,p)) return 0;
    bool l=!!(*p)->rama[0];
    bool r=!!(*p)->rama[1];
    if(l&r)
    {
        q=remplazo(p);
        (*p)->dato=(*q)->dato;
        p=q;
        l=!!(*p)->rama[0];
        r=!!(*p)->rama[1];
    }

    if(!l & !r)
    {

        delete *p;
        *p=0;
        return 1;

    }

    Nodo<TipoT>* t= *p;
    *p=(*p)->rama[r];
    delete t;
    return 1;

}

#endif // ARBOLBINARIO_H
