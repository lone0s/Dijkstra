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

AdjacencyList &AdjacencyList::operator=(const AdjacencyList &list) {
    if (this != &list) {
        delete this->node;
        std::cout << "\nJust deleted the old node mf\n";
        if (list.node)
            this->node = new Node(list.node->getIdParentVertex(), list.node->getNbSuccessors(),
                                  list.node->getSuccessors());
        else
            this->node = nullptr;
    }
    return *this;
}



