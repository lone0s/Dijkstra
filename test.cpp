//
// Created by jeune on 22/12/2022.
//
#include <iostream>
#include "DataStructures/T_List.h"
#include "DataStructures/T_PriorityQueue.h"
#include "Graph/Graph.h"

using namespace Dijkstra_DataTypes;
using namespace std;
int main() {
/*    T_List<int> list((size_t)4);
    cout << list;
    T_List<int > list2((size_t)4);
    list2 = list;
    list.add(1);
    list2.add(2);
    cout << list;
    cout << list2;
    list = list2;
    cout << list;
    cout << list2;
    T_PriorityQueue<int> priorityQueue;
    priorityQueue.add(1);
    T_PriorityQueue<int> priorityQueue1;
    priorityQueue1.add(2);
    priorityQueue = priorityQueue1;
    cout << priorityQueue;
    cout << priorityQueue1;*/
    /*Sommet a;
    Sommet b;
    cout << a;
    cout << b;
    a = b;
    cout << a ;
    cout << b;
    Graph graph;
    Graph graph1;
    graph1 = graph;
    cout << graph;
    Sommet sommet(1);
    Successeur test(1, 1);
    sommet.addSuccesseur(test);
    graph.addSommet(sommet);
    graph1 = graph;
    cout << graph;
    cout << graph1;
    */
    T_List<int> a;
    a.add(1);
    T_List<int> b;
    b.add(2);
    cout << a;
    cout << b;
    a = b;
    cout << a;
    cout << b;
    a.add(1);
    cout << a;
    cout << b;
    b.add(3);
    cout << a;
    cout << b;
    return 0;
}
