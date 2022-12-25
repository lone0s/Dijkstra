//
// Created by jeune on 22/12/2022.
//
#include <iostream>
#include "AdjacencyList/Successor.h"

using namespace std;
using namespace AdjacencyList;
int main() {
    Successor test(1,4);
    test.getSuccessorId() == 1 ? (cout << "Correct id\n") : (cout << "Wrong id\n");
    test.getSuccessorWeight() == 4 ? (cout << "Correct weight\n") : (cout << "Wrong weight\n");
    cout << test;
}