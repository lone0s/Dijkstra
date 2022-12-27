//
// Created by jeune on 26/12/2022.
//

#pragma once

#include "Node/Node.h"

namespace Dijkstra_List {

    class AdjacencyList {

    private:
        AdjacencyList_Node::Node* node;

    public:
        AdjacencyList();
        explicit AdjacencyList(const int idVertex);
        AdjacencyList(const int idVertex, const size_t nbSuccessors, const Dijkstra_Successor::Successor successors[]);
        AdjacencyList(const AdjacencyList& list);

        AdjacencyList& operator =(const AdjacencyList& list);

        ~AdjacencyList();

        inline int getIdVertexParent() const {
            if (node)
                return node -> getIdParentVertex();
            throw std::exception(); //Voir par quel genre d'exception remplacer si Node pas init
        }

        inline Dijkstra_Successor::Successor& operator[] (size_t i) const {
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

