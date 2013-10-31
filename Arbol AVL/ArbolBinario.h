#ifndef ARBOLBINARIO_H
#define ARBOLBINARIO_H
#include "Nodo.h"
#include "TraitMayor.h"
#include <iostream>
#include <stack>
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
        virtual ~ArbolBinario() {

            masacre(cabeza);

        }
        bool buscar (TipoT d, Nodo<TipoT> ** &p,stack<Nodo<TipoT>** > &pila);
        bool busquedaNodo(TipoT d, Nodo<TipoT> * &p2);
        bool insertar (TipoT d);
        bool eliminar (TipoT n);
        Nod remplazo (Nod t);
        void inorder( Nodo<TipoT>* t);
        void masacre(Nodo<TipoT> * t);
        void rotar(Nodo<TipoT>** &t, bool izquierda);
        void doblerotacion(Nodo<TipoT>** t, bool izquierda);
        void balancear(Nodo<TipoT>**t);
        void todobalance(stack<Nodo<TipoT>** > &pila);
    protected:
    private:
};

template<typename Tr>
void ArbolBinario<Tr>::todobalance(stack<Nodo<TipoT>** > &pila)
{

    while(!pila.empty())
    {
    balancear(pila.top());
    pila.pop();
    }
}

template<typename Tr>
void ArbolBinario<Tr>::balancear(Nodo<TipoT>**t)
{
    if(t)
    {
        if((*t)->altura[0]-(*t)->altura[1]==2)
        {
            if((*t)->rama[0]->altura[0]>= (*t)->rama[0]->altura[1])
            {
                rotar(t,1);
            }
            else
            {
                doblerotacion(t,1);
            }
        }

        else if((*t)->altura[1]-(*t)->altura[0]==2)
        {
            if((*t)->rama[1]->altura[1]>= (*t)->rama[1]->altura[0])
            {
                rotar(t,0);
            }
            else
            {
                doblerotacion(t,0);
            }

        }
    }
}

template<typename Tr>
bool ArbolBinario<Tr>::busquedaNodo(TipoT d, Nodo<TipoT>* &p2)
{
    if (p2==NULL) return false;
      while(p2!=NULL)
    {
        if(p2->rama[0]!=NULL or p2->rama[1]!=NULL)
            p2->altura[Compa(p2->dato,d)]++;
        p2=p2->rama[Compa((p2->dato),d)];
    }
    return true;

}

template<typename Tr>
void ArbolBinario<Tr>::rotar(Nodo<TipoT>** &t,bool izquierda)
{

    Nodo<TipoT> * tmp= *t;
    *t=(*t)->rama[!izquierda];
    tmp->rama[!izquierda]=(*t)->rama[izquierda];
    (*t)->rama[izquierda]=tmp;
}

template<typename Tr>
void ArbolBinario<Tr>::doblerotacion(Nodo<TipoT>** t, bool izquierda)
{
    rotar(t,izquierda);
    Nodo<TipoT>** tmp=&(*t)->rama[!izquierda];
    rotar(tmp,!izquierda);
}



template<typename Tr>
void ArbolBinario<Tr>::masacre(Nodo<TipoT> * t)
{
        if(!t) return;
        masacre(t->rama[0]);
        masacre(t->rama[1]);
        delete t;
}

template<typename Tr>
void ArbolBinario<Tr>::inorder( Nodo<TipoT>* t)
{
    if (!t)return;
    inorder ((t)->rama[0]);
    cout<<(t)->dato<<"\t";
    inorder((t)->rama[1]);

}

template <typename T>
typename ArbolBinario<T>::Nod ArbolBinario<T>::remplazo(Nod t)
{
    t=&cabeza;
    (t)=&(*t)->rama[0];
    while ((*t)->rama[1]!= NULL)
    {

        (t)= &(*t)->rama [1];

    }
    return t;
}

template<typename Tr>
bool ArbolBinario<Tr>::buscar(TipoT d, Nodo <TipoT> ** &p, stack<Nodo<TipoT>** > &pila)
{


    for(p=&cabeza;*p;p=&(*p)->rama[Compa((*p)->dato,d)])
    {
        pila.push(p);
        if ((*p)-> dato == d)
        {

            return 1;
        }

    }



    return 0;
}

template <typename Tr>
bool ArbolBinario<Tr>::insertar (TipoT d)
{
    stack<Nodo<TipoT> ** > pila;
    Nodo<TipoT> *p2=cabeza;
    Nodo<TipoT> **p;
    if (buscar(d,p,pila))
        return false;
    busquedaNodo(d,p2);
    *p=new Nodo<TipoT>(d);
    todobalance(pila);

    return true;

}

template <typename Tr>
bool ArbolBinario<Tr>::eliminar (TipoT n)
{
    stack <Nodo <TipoT> ** > pila;
    Nodo<TipoT>** p;
    Nodo<TipoT>** q;
    p=&cabeza;
    if (!buscar(n,p,pila)) return 0;
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
        *p=NULL;
        todobalance(pila);
        return 1;

    }

    Nodo<TipoT>* t= *p;
    *p=(*p)->rama[r];
    delete t;
    todobalance(pila);
    return 1;

}

#endif // ARBOLBINARIO_H
