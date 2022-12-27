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

adjacencyList::adjacencyList(const adjacencyList &list) {
    this -> node = new Node(list.node->getIdParentVertex(),list.node->getNbSuccessors(),list.node->getSuccessors());
}

adjacencyList &adjacencyList::operator=(const adjacencyList &list) {
    //Plusieurs facteurs : est ce que nullptr du node de list ? Si non, est ce que this est null ?
    if (this != &list) {
        if (this -> node)
            delete this -> node;
        else {
            if (list.node != nullptr)
                this->node = new Node(list.node->getIdParentVertex(), list.node->getNbSuccessors(),
                                      list.node->getSuccessors());
            else
                this->node = nullptr;
        }
    }
    return *this;
}

