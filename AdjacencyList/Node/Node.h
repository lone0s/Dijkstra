//
// Created by jeune on 22/12/2022.
//

#pragma once

#include <iostream>
#include "../../Successor/Successor.h"

namespace AdjacencyList_Node {
    /***
     * Structures internes d'une liste d'adjacence
     * afin de respecter l'information hiding
     */
    class Node {
        private:
        //Identifiant du sommet "parent"
        int idVertex;
        size_t numberSuccessors;
        //Tableau contenant les successeurs;
        Dijkstra_Successor::Successor* arraySuccessors;


        public:
        explicit Node(const int idParent);
        explicit Node(const int idParent, const size_t nbSuccs, const Dijkstra_Successor::Successor array[]);

        ~Node();

//        add operator de recopie !!!

        inline Dijkstra_Successor::Successor& operator[] (size_t i) {
            if ((i < this -> numberSuccessors) && (this -> arraySuccessors))
                return this -> arraySuccessors[i];
            if (! this -> arraySuccessors)
                throw std::invalid_argument("There's currently no successors");
            throw std::invalid_argument("Incorrect range value, i should be between 0 and " + std::to_string(this -> numberSuccessors - 1));
        }

        inline int getIdParentVertex() const {
            return this -> idVertex;
        };

        inline size_t getNbSuccessors() const {
            return this -> numberSuccessors;
        }

        inline void addSuccessors(const size_t nbSuccs, const Dijkstra_Successor::Successor array[]) {
            this -> numberSuccessors = nbSuccs;
            if (this -> arraySuccessors)
                delete[] this -> arraySuccessors;
            this -> arraySuccessors = new Dijkstra_Successor::Successor[nbSuccs];
            for(size_t i = 0 ; i < nbSuccs ; ++i) {
                    this -> arraySuccessors[i] = array[i];
                }
        }

        inline Dijkstra_Successor::Successor* getSuccessors() const{
            return this -> arraySuccessors;
        }
    };
}
