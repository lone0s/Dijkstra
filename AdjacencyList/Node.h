//
// Created by jeune on 22/12/2022.
//

#pragma once

#include "Successor.h"

namespace AdjacencyList {
    /***
     * Structures internes d'une liste d'adjacence
     * afin de respecter l'information hiding
     */
    class Node {
        private:
        //Identifiant du sommet "parent"
        const int idVertex;
        const int nbSuccessors;
        //Tableau contenant les successeurs;
        Successor* successorArray[];

        public:
        inline Node(const int idParent, int arraySize, const Successor array[]) : idVertex(idParent), nbSuccessors(arraySize){
        }
    };
}
