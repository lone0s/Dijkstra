//
// Created by jeune on 26/12/2022.
//

#include "AdjacencyList.h"

using namespace AdjacencyList;

adjacencyList::adjacencyList() {
    this -> node = nullptr;
}

adjacencyList::adjacencyList(const int idVertex) {
    this -> node = new Node(idVertex);
}

adjacencyList::adjacencyList(const int idVertex, const size_t nbSuccessors, const Successor successors[]) {
    this -> node = new Node(idVertex,nbSuccessors,successors);
}

adjacencyList::~adjacencyList() {
    if (node)
        delete node;
}