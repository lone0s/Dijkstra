//
// Created by jeune on 22/12/2022.
//
#include <iostream>
#include "DataStructures/T_List.h"
#include "DataStructures/T_PriorityQueue.h"
#include "Graph/Graph.h"

using namespace std;
int main() {
    T_List<int> list((size_t)4);
    list.add(1);
    cout << list;
    T_List<int > list2((size_t)4);
    list2.add(2);
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
    cout << priorityQueue1;
}
