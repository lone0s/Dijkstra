//
// Created by jeune on 22/12/2022.
//
#include <iostream>
#include "DataStructures/T_List.h"
#include "DataStructures/T_PriorityQueue.h"
#include "Graph/Graph.h"
#include "Dijkstra.h"

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
    cout << priorityQueue1;*//*

    */
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
    *//*

    */
/*T_List<int> a;
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
    *//*

*/
/*    T_PriorityQueue<int> a;
    a.add(1);
    a.add(2);
    a.add(3);*//*

//    cout << a.find(5);


    Successeur a1(2, 1);
    Successeur b1(3, 2);
    Successeur c1(3, 2);
    Successeur idk(1, 1);
    Successeur a2(1,0);
    Sommet s(1);
    s.addSuccesseur(a1);
    s.addSuccesseur(b1);
    Sommet s1(2);
    s1.addSuccesseur(c1);
    Sommet s2(3);
    s2.addSuccesseur(idk);
    Graph graph;
    graph.addSommet(s);
    graph.addSommet(s1);
    graph.addSommet(s2);
//    cout << graph;
    // Vérifier avant d'updatePriority priorité que les successeurs ont same id
*/
/*    T_PriorityQueue<Successeur> b;
    b.add(a1);
    b.add(b1);
    b.add(c1);
    cout << b;
    b.updatePriority(a2);
    cout << b;
    b.updatePriority(a1);
    cout << b;
    b.updatePriority(Successeur(1,-1));
    cout << b;
    cout << b;*//*

*/
    Dijkstra dijkstra("a", 1);
    /*for (size_t i = 0; i < dijkstra.graph.length(); i++) {
        cout << dijkstra.distances[i] << endl;
    }*/
    dijkstra.executeDijkstra(1);
    return 0;

}
