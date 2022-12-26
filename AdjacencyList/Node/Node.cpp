//
// Created by jeune on 22/12/2022.
//

#include "Node.h"
#include <iostream>

AdjacencyList::Node::Node(const int idParent) : idVertex(idParent), numberSuccessors(0), arraySuccessors(nullptr) {
}

AdjacencyList::Node::Node(const int idParent, const size_t nbSuccs, const AdjacencyList::Successor array[]) : idVertex(idParent), numberSuccessors(nbSuccs) {
    this -> arraySuccessors = new Successor[nbSuccs];
    for(size_t i = 0 ; i < nbSuccs ; ++i) {
        this -> arraySuccessors[i] = array[i];
    }
}

AdjacencyList::Node::~Node() {
    if(arraySuccessors)
        delete[] arraySuccessors;
}


