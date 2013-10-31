#ifndef GRAPH_H
#define GRAPH_H
#include "node.h"
#include "edge.h"
#include <stack>
#include <vector>
using namespace std;
/**\class Graph
    \brief Esta clase es la clase del Grafo, aqui estan todas sus funciones
*/

template<typename N, typename E>
class Graph
{
    public:

        friend class Test;

        //definiciones de variables (typedef)
        typedef Graph<N,E> self;

        /**
            \typedef self
            \brief es el mismo grafo en si
        */

        typedef N tnode;
        /** \typedef tnode
            \brief este es el tipo propio del nodo
        */
        typedef E tedge;
        /**
            \typedef tedge
            \brief este es el tipo propio de la arista
        */
        typedef Node<self> node;
        /**
            \typedef node
            \brief se refiere al nodo
        */
        typedef Edge<self> edge;

        /** \typedef edge
            \brief se refiere a la arista
        */

        typedef typename vector<node*>::iterator viterator;
        typedef typename node::eiterator eiterator;


        Graph() {}
        virtual ~Graph() {}

        // Funciones

        bool FindNode(tnode d, typename vector<node*>::iterator & i); /**<esta funcion buscara un dato dentro del vector de nodos para ver si esta o no ( "true (1)" si es que esta o "false(0)" si es que no esta) */
        bool InsertNode(tnode d); /**< esta funcion insertara un nodo con algun dato si es que este ya no se encuentra dentro del grafo */
        bool InsertEdge(tnode from, tnode to, tedge d, bool dir);/**<inserta una arista, depende de 'dir' si es 0 es bidireccional y 1 si es direccionado*/
        bool InsertEdgeFromPointer(node* from, node* to, tedge d, bool dir);/**< Insertamos una Arista recibiendo los punteros a los nodos*/
        bool RemoveEdge(tnode from, tnode to); /**< Se removera la Arista entre los nodos indicados*/
        bool RemoveNode(tnode d); /**<Se removera el nodo indicado mas todas las aristas que lo involucran*/
        void Print(); /**<Esta funcion recorrera e imprimira todos los nodos con las aristas que salen de el*/
        vector<node*>* GetGnodes();/**<Se retornara el vector de nodos del Grafo*/

        vector<node*> gnodes; /**< aqui tenemos al vector de nodos que tendremos dentro del grafo, dentro de estos esta cada arista y a donde apuntan */
    protected:
    private:



};

template<typename N, typename E>
vector<typename Graph<N,E>::node *>* Graph<N,E>::GetGnodes()
{
    return &gnodes;
}

template<typename N, typename E>
bool Graph<N,E>::FindNode(tnode d, viterator &i)
{
    for(i=gnodes.begin();i!=gnodes.end();i++)
    {
        if ((*i)->data == d) return true;
    }
    return false;

}

template<typename N, typename E>
bool Graph<N,E>::InsertNode(tnode d)
{
    viterator i;
    if(FindNode(d,i))return false;
    node * tmp=new node(d);
    gnodes.push_back(tmp);

    return true;
}

template<typename N,typename E>
bool Graph<N,E>::InsertEdgeFromPointer(node* from, node* to, tedge d, bool dir)
{
  typename node::eiterator i;
  if((*from).FindEdge(to,i)){
    if((*i)->nod[1]==from and (*i)->nod[0]==to)
    {
        (*i)->dir=0;
    }
    return false;
    }
  edge*tmp =new edge(d,from,to,dir);
  from->nedges.push_back(tmp);
  if(from->data != to-> data) to->nedges.push_back(tmp);
  return true;
}

template<typename N,typename E>
bool Graph<N,E>::InsertEdge(tnode from, tnode to, tedge d, bool dir)
{
    viterator f;
    viterator t;
    if(FindNode(from,f)and FindNode(to, t))
        return InsertEdgeFromPointer(*f,*t,d,dir);
    return false;

}
template<typename N,typename E>
bool Graph<N,E>::RemoveEdge(tnode from, tnode to)
{
    eiterator eif;
    eiterator eit;
    viterator f;
    viterator t;
    if(!(FindNode(from,f) and FindNode(to,t)))
        return false;
    (*f)->FindEdge(*t,eif);
    (*t)->FindEdge(*f,eit);
    delete *eif;
    (*f)->nedges.erase(eif);
    if(from!=to)
        (*t)->nedges.erase(eit);
    return true;
}

template<typename N,typename E>
bool Graph<N,E>::RemoveNode(tnode d)
{
    viterator i;
    if(!FindNode(d,i))
        return false;
    typename node::eiterator ei;
    for(ei=(*i)->nedges.begin();ei<=(*i)->nedges.end();ei++)
    {
      RemoveEdge((*i)->data, (*ei)->nod[1]->data);

    }
    delete *i;
    gnodes.erase(i);
    return true;
}

template<typename N, typename E>
void Graph<N,E>::Print()
{

    for(viterator i=gnodes.begin();i!=gnodes.end();i++)
    {
        cout<<"Nodo: "<<(*i)->data<<endl;

        for(eiterator x=(*i)->nedges.begin();x!=(*i)->nedges.end();x++)
        {

            if( (*x)->nod[0]==*i)
            {

                if((*x)->dir==0) cout<<"\n\tArista Bidireccionada entre "<<(*i)->data<<" hasta "<< (*x)->nod[1]->data<< " y de peso "<<(*x)->data;
                else cout<<"\n\tArista que va desde: "<< (*i)->data<<" hasta " << (*x)->nod[1]->data<< " y de peso "<<(*x)->data;


            }

            if((*x)->nod[1]==*i && (*x)->dir==0) cout<<"\n\tArista Bidireccionada entre "<<(*i)->data<<" hasta "<< (*x)->nod[0]->data<< " y de peso "<<(*x)->data;
        }

            cout<<"\n\n\n"<<endl;

        }

    }




#endif // GRAPH_H
