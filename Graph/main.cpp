#include <iostream>
#include "graph.h"
#include "node.h"
#include "edge.h"
#include "test.h"
#include <stack>
#include <vector>
using namespace std;

/* Intento 1
template<typename N,typename E>
stack< pair<typename Graph<N,E>::node *, typename Graph<N,E>::edge*> > Dijkstra (Graph<N,E> a, typename Graph<N,E>::tnode from, typename Graph<N,E>::tnode to)
{
    typedef Graph<N,E> graph;
    typedef typename Graph<N,E>::edge edge;
    typedef typename Graph<N,E>::node node;
    typedef typename Graph<N,E>::tnode tnode;
    typedef typename Graph<N,E>::tedge tedge;
    typedef typename Graph<N,E>::viterator viterator;
    typedef pair<node*,edge*> _pair;
    typedef vector< _pair > vector_pair;
    typedef vector < pair<vector_pair*, _pair> > vector_path;
    typedef typename node::eiterator eiterator;
    typedef stack<vector_path> path_tmp;

    viterator vector_iterator_from;
    viterator vector_iterator_to;
    typedef typename vector_path::iterator path_iterator;

    vector_path init;
    stack<_pair> path;

    stack< path_tmp > path_for;

    if(!(a.FindNode(from,vector_iterator_from)&&a.FindNode(to,vector_iterator_to)))
        return path;

    for(eiterator i= (*vector_iterator_from)->nedges.begin();i!=(*vector_iterator_from)->nedges.end();i++)
    {

        _pair tmp;
        tmp.first=*vector_iterator_from;
        tmp.second=*i;
        vector_pair* null_vector;
        pair<vector_pair*,_pair> tmp_to_vector;
        tmp_to_vector.first=null_vector;
        tmp_to_vector.second=tmp;
        init.push_back(tmp_to_vector);

    }

    node* from_to=*vector_iterator_from;

    for(path_iterator i=init.begin();i!=init.end();i++)
    {
        path_tmp t;
        while(from_to!= *vector_iterator_to)
        {
            vector_path tmp3;
            for(eiterator a= from_to->nedges.begin();a!=from_to->nedges.end();i++)
            {
                _pair tmp;
                tmp.first=*vector_iterator_from;
                tmp.second=*a;
                vector_pair* null_vector;
                pair<vector_pair*,_pair> tmp_to_vector;
                tmp_to_vector.first=null_vector;
                tmp_to_vector.second=tmp;
                tmp3.push_back(tmp_to_vector);
                t.push(tmp3);

            }


        }


    }



    return path;

}
*/

/* Intento 2

/** \fn Dijkstra
    \brief Hallara la ruta mas corta entre dos nodos

    Primero se hallara un vector de todos los nodos y sus aristas
      for(viterator i=a.gnodes.begin();i!=a.gnodes.end();i++)
    {
        pair<node*,vector<edge*> *> tmp_pair;
        tmp_pair.first=*i;
        tmp_pair.second=&((*i)->nedges);
        __nodes.push_back(tmp_pair);
    }
    de ahi buscaremos todos contra todos los caminos que llegan al nodo que se usara



template<typename N,typename E>
stack< pair<typename Graph<N,E>::node *, typename Graph<N,E>::edge*> > Dijkstra (Graph<N,E> a, typename Graph<N,E>::tnode from, typename Graph<N,E>::tnode to)
{
    typedef Graph<N,E> graph;
    typedef typename Graph<N,E>::edge edge;
    typedef typename Graph<N,E>::node node;
    typedef typename Graph<N,E>::tnode tnode;
    typedef typename Graph<N,E>::tedge tedge;
    typedef typename Graph<N,E>::viterator viterator;
    typedef pair<node*,edge*> _pair;
    typedef vector<pair<node*, vector<edge*>* > > vector_useful;
    typedef typename node::eiterator eiterator;


    viterator vector_iterator_from;
    viterator vector_iterator_to;
    viterator graph_iterator;


    vector_useful __nodes;
    vector < vector<edge*> > vector_edges;
    stack<_pair> path;


    if(!(a.FindNode(from,vector_iterator_from)&&a.FindNode(to,vector_iterator_to)))
        return path;

    //hallar vector de nodos con sus aristas
    for(viterator i=a.gnodes.begin();i!=a.gnodes.end();i++)
    {
        pair<node*,vector<edge*> *> tmp_pair;
        tmp_pair.first=*i;
        tmp_pair.second=&((*i)->nedges);
        __nodes.push_back(tmp_pair);
    }


    //todos contra todos



    return path;

}

*/


//intento 3 bota resultado de camino no optimo
/**
    \fn Dijkstra
    \brief Encuentra una ruta del nodo from al nodo to

    Este algoritmo no encuentra la ruta optima, solo encuentra una ruta, vamos pasando de nodo a nodo y si encontramos algun nodo
    que no tiene salida volvemos al anterior y seguimos intentando, como vemos aca
     if(t->no_way_out(tmp))
        {
            t=tmp_t;
            i++;
            t=t->nedges[i]->nod[0];
            continue;
        }
    Al final solo encontramos la primera ruta y la ponemos en nuestro stack
*/
template<typename N,typename E>
stack< pair<typename Graph<N,E>::node *, typename Graph<N,E>::edge*> > Dijkstra (Graph<N,E> a, typename Graph<N,E>::tnode from, typename Graph<N,E>::tnode to)
{
    typedef Graph<N,E> graph;
    typedef typename Graph<N,E>::edge edge;
    typedef typename Graph<N,E>::node node;
    typedef typename Graph<N,E>::viterator viterator;
    typedef pair<node*,edge*> _pair;
    typedef typename vector<node*>::iterator vnodeiterator;
    typedef  typename vector<edge*>::iterator vedgeiterator;

    viterator vector_iterator_from;
    viterator vector_iterator_to;

    stack<_pair> path;
    vector<node*> vector_of_nodes;

    if(!(a.FindNode(from,vector_iterator_from)&&a.FindNode(to,vector_iterator_to)))
        return path;

    node* t= *vector_iterator_from;
    node* to_point;

    int i=0;
    while(t!=*vector_iterator_to)
    {

        edge* tmp;
        node* tmp_t=t;
        if(t->no_way_out(tmp))
        {
            t=tmp_t;
            i++;
            t=t->nedges[i]->nod[0];
            continue;
        }

        if(t->nedges[i]->nod[1]->data==t->data)
        {
            i++;
        }
        vector_of_nodes.push_back(t);
        cout<<t->data;
        t=t->nedges[i]->nod[1];
    }

    for(vnodeiterator i=vector_of_nodes.begin();i!=vector_of_nodes.end();i++)
    {
        vedgeiterator tmp2;
        vnodeiterator tmp= i++;
        i--;

        (*i)->FindEdge(*tmp,tmp2);
        _pair to_stack;
        to_stack.first=*i;
        to_stack.second=*tmp2;
        path.push(to_stack);
    }

    return path;

}

int main()
{

    Test b;
    b.Run();

    Graph<char, int> a;
    a.InsertNode('A');
    a.InsertNode('B');
    a.InsertNode('C');
    a.InsertNode('D');
    a.InsertNode('E');
    a.InsertEdge('A','B',4,1);
    a.InsertEdge('A','C',3,1);
    a.InsertEdge('B','C',1,1);
    a.InsertEdge('D','A',6,1);
    a.InsertEdge('B','A',4,1);
    a.InsertEdge('C','E',10,1);
    a.InsertEdge('E','D',2,1);
    a.Print();
    Dijkstra(a,'A','E');
    return 0;
}
