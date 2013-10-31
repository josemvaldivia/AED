#ifndef TEST_H
#define TEST_H
#include "graph.h"
#include "node.h"
#include "edge.h"
#include <assert.h>


/** \class Test
    \brief En esta clase se probaran todas las funciones y caracteristicas del grafo, usaremos assert para todo
*/

class Test
{
    public:
        Test() {}
        virtual ~Test() {}
        void Run(); /**< Correra todas las pruebas de unidad */
        void CreateNodeTest(); /**<Prueba si la creacion de un nodo es correcta*/
        void CreateEdgeTest();/**<Prueba si la creacion de una arista es correcta*/
        void RemoveEdgeTest();/**<Prueba si se elimina correctamente a las aristas*/
        void CreateAndRemoveEdgeLoop();/**<prueba que se remuevan las aristas de los bucles */
        void RemoveNodeTest();/**<prueba que se remuevan los nodos*/
        void BidirectionalEdge(); /**<prueba que una arista se vuelva bidireccional si es que se le agrega una arista de ida y vuelta y la otra en viceversa*/
    protected:
    private:
};

void Test::Run()
{
    this->CreateNodeTest();
    this->CreateEdgeTest();
    this->RemoveEdgeTest();
    this->CreateAndRemoveEdgeLoop();
    this->RemoveNodeTest();
    this->BidirectionalEdge();

}

void Test::CreateNodeTest()
{
    Graph<char, int> a;
    a.InsertNode('A');
    assert(a.gnodes[0]->data=='A');
}

void Test::CreateEdgeTest()
{
    Graph<char, int> a;
    a.InsertNode('A');
    a.InsertNode('B');
    a.InsertEdge('A','B',4,1);
    assert(a.gnodes[0]->nedges[0]->data==4);
    assert(a.gnodes[1]->nedges[0]->data==4);
}

void Test::RemoveEdgeTest()
{
    Graph<char, int> a;
    a.InsertNode('A');
    a.InsertNode('B');
    a.InsertEdge('A','B',4,1);
    a.RemoveEdge('A','B');
    bool x=a.gnodes[0]->nedges.empty();
    bool y=a.gnodes[1]->nedges.empty();
    assert(x==1);
    assert(y==1);
}

void Test::CreateAndRemoveEdgeLoop()
{
    Graph<char, int> a;
    a.InsertNode('A');

    a.InsertEdge('A','A',4,1);
    a.RemoveEdge('A','A');
    bool x=a.gnodes[0]->nedges.empty();
    assert(x==1);

}

void Test::RemoveNodeTest()
{
    Graph<char, int> a;
    a.InsertNode('A');
    a.InsertNode('B');
    a.InsertNode('C');
    a.InsertNode('D');
    a.InsertEdge('A','B',4,1);
    a.RemoveNode('B');
    assert(a.gnodes[0]->data=='A');
    assert(a.gnodes[1]->data=='C');
    assert(a.gnodes[0]->nedges.empty()==0);
}
void Test::BidirectionalEdge()
{

    Graph<char, int> a;
    a.InsertNode('A');
    a.InsertNode('B');
    a.InsertNode('C');
    a.InsertNode('D');
    a.InsertEdge('A','B',4,1);
    a.InsertEdge('A','C',3,1);
    a.InsertEdge('B','C',1,1);
    a.InsertEdge('D','A',6,1);
    assert(a.gnodes[0]->nedges[0]->dir==1);
    a.InsertEdge('B','A',4,1);
    assert(a.gnodes[0]->nedges[0]->dir==0);
}

#endif // TEST_H
