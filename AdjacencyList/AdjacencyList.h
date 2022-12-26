//
// Created by jeune on 26/12/2022.
//

#pragma once

#include "Node/Node.h"

namespace AdjacencyList {

    class adjacencyList {

    private:
        Node* node;

    public:
        adjacencyList();
        explicit adjacencyList(const int idVertex);
        adjacencyList(const int idVertex, const size_t nbSuccessors, const Successor successors[]);


        ~adjacencyList();
    };

}

