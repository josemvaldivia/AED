#ifndef EDGE_H
#define EDGE_H
#include <stack>
#include "node.h"
#include "graph.h"
using namespace std;

/** \class Edge
    \brief Crea a las aristas propias de los nodos dentro del grafo, aqui sus variables y funciones
*/
template <typename G>
class Edge
{
    public:
        friend class Test;


        template<typename N,typename E> friend class Graph;
        template<typename A> friend class Node;
        typedef typename G::tedge edtype;
        /** \typedef edtype
            \brief se refiere a edge data type (EDT); el tipo de dato de la arista
        */
        typedef typename G::node node;

        /** \typedef node
            \brief este es el nodo
        */



        Edge(edtype d,node* from, node* to,bool di)/**<El constructor de la Arista, recibira de donde viene, a donde va y su direccion*/
        {
            data=d;
            nod[0]=from;
            nod[1]=to;
            dir=di;
        }
        virtual ~Edge() {}

        node** GetNod();/**< se obtiene los nodos de donde viene y a donde va de la arista*/
        edtype* GetData();/**< se obtendra el dato contenido en la Arista*/
        bool* GetDir();/**< se obtendra si es bidireccional o con una sola direccion la Arista*/

        node* nod [2]; /**<  la posicion [0] se referira del nodo al que sale y la [1] al que apunta */

    protected:
    private:
        edtype data;    /**< el dato que guardara la arista */

        bool dir; /**<  direction indicara 0 si es bidireccional o 1 si solo apunta a un lado */
};

template<typename G>
typename Edge<G>::node** Edge<G>::GetNod()
{
    return & nod;
}

template<typename G>
typename Edge<G>::edtype* Edge<G>::GetData()
{
    return &data;
}

template<typename G>
bool* Edge<G>::GetDir()
{
    return &dir;
}




#endif // EDGE_H
