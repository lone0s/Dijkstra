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
        adjacencyList(const adjacencyList& list);

        adjacencyList& operator =(const adjacencyList& list);

        ~adjacencyList();

        inline int getIdVertexParent() const {
            if (node)
                return node -> getIdParentVertex();
            throw std::exception(); //Voir par quel genre d'exception remplacer si Node pas init
        }

        inline Successor& operator[] (size_t i) const {
            if (node) {
                try{
                    node[i];
                }
                catch (std::invalid_argument& e) {
                    std::cerr << e.what() << std::endl;
                }
            }
            throw std::exception(); //Voir par quel genre d'exception remplacer si Node pas init
        };

        inline size_t getLengthSuccessors() const{
            if (node)
                return node -> getNbSuccessors();
             return -1;
        }
        /* Besoin de get idVertex
         * get un successeur particulier
         * get les successeurs
         */

    };

}

