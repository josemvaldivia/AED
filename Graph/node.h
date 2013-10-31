#ifndef NODE_H
#define NODE_H
#include "graph.h"
#include "edge.h"
#include <vector>
#include <stack>
using namespace std;

/** \class Node
    \brief Aqui esta la clase nodo que crea a cualquier nodo dentro del grafo, aqui sus funciones y variables que contiene

*/
template <typename G>
class Node
{
    public:

        friend class Test;


        template<typename N,typename E> friend class Graph;
        //definiciones de tipo
        typedef typename G::tnode ndtype;
        /** \typedef ndtype
            \brief  se refiere a node data type (NDT); el tipo de dato del nodo
        */
        typedef typename G::edge edge;
        /**
            \typedef edge
            \brief esta es la arista
        */
        typedef typename G::node node;
         /**
            \typedef node
            \brief este es el mismo nodo
        */


        typedef typename vector<edge*>::iterator eiterator;

        //funciones



        Node( ndtype d) {
            data=d;
        }
        virtual ~Node() {}

        bool FindEdge (node* to,eiterator &i); /**< esta funcion buscara que se encuentre la arista que apunta al nodo "to" ingresado */
        ndtype* GetData();/**<se retornara el dato del nodo*/
        vector<edge*>* GetNedges();/**<Se retornara el vector de aristas del grafo*/
        template<typename A,typename B> friend stack< pair<node *, edge*> > Dijkstra (typename G::self a, ndtype from,ndtype to);
        vector<edge*> nedges; /**<   todas las aristas que entraran o saldran del nodo*/
        bool no_way_out(edge * &a);/**<busca si el nodo tiene alguna salida o no*/

        ndtype data; /**<  el dato que guardara el nodo */
    protected:
    private:


};

template<typename G>
bool Node<G>::no_way_out(edge* &a)
{
    for(int i=0;i<nedges.size();i++)
    {
        a=nedges[i];
        if(a->nod[0]== this)
            return false;
    }

    return true;
}

template<typename G>
typename Node<G>::ndtype* Node<G>::GetData()
{
    return &data;
}

template<typename G>
vector<typename Node<G>::edge*>* Node<G>::GetNedges()
{

    return &nedges();

}

template<typename G>
bool Node<G>::FindEdge(node* to, eiterator & i)
{

    for(i=nedges.begin();i!=nedges.end();i++)
    {
        if((*i)->nod[1]==to or (*i)->nod[0]==to) return true;
    }
    return false;
}




#endif // NODE_H
