//
// Created by jeune on 26/12/2022.
//

#include "AdjacencyList.h"

using namespace AdjacencyList_Node;
using namespace Dijkstra_List;
using namespace Dijkstra_Successor;

AdjacencyList::AdjacencyList() {
    this -> node = nullptr;
}

AdjacencyList::AdjacencyList(const int idVertex) {
    this -> node = new Node(idVertex);
}

AdjacencyList::AdjacencyList(const int idVertex, const size_t nbSuccessors, const Successor successors[]) {
    this -> node = new Node(idVertex,nbSuccessors,successors);
}

AdjacencyList::~AdjacencyList() {
    if (node)
        delete node;
}

AdjacencyList::AdjacencyList(const AdjacencyList &list) {
    this -> node = new Node(list.node->getIdParentVertex(),list.node->getNbSuccessors(),list.node->getSuccessors());
}

//Plusieurs facteurs : est ce que nullptr du node de list ? Si non, est ce que this est null ?
AdjacencyList &AdjacencyList::operator=(const AdjacencyList &list) {
    if (this != &list) {
        delete this->node;
        if (list.node)
            this->node = new Node(list.node->getIdParentVertex(), list.node->getNbSuccessors(),
                                  list.node->getSuccessors());
        else
            this->node = list.node;
    }
    return *this;
}
/*
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
    return *this;*/
}



