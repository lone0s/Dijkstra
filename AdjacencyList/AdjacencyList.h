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

        inline size_t lengthSuccessors() const{
            if (node)
                return node -> getNbSuccessors();
             return -1;
        }

        /*** Overloaded operators ***/
        inline Dijkstra_Successor::Successor& operator[] (size_t i) const{
            if (node)
                return (*this -> node)[i];
            throw std::exception(); //Voir par quel genre d'exception remplacer si Node pas init
        };

        inline friend std::ostream& operator << (std::ostream& ostream, const AdjacencyList& list) {
            ostream << "--- Liste adjacence sommet : " << list.getIdVertexParent()
            << " | "<< list.lengthSuccessors();
            list.lengthSuccessors() > 1 ? ostream <<  " sommets adjacents ---\n[" : ostream <<  " sommet adjacent ---\n[";
            for (size_t i = 0 ; i < list.lengthSuccessors() ; ++i) {
                ostream << list[i];
                if (i != list.lengthSuccessors() - 1)
                    ostream << " ; " ;
            }
            ostream << "]";
            return ostream;
        }
    };

}

