//
// Created by ohno on 1/20/2023.
//

#include "Sommet.h"
using namespace Dijkstra_DataTypes;

/******************************************* SURCHARGE OPERATEUR *****************************************************/

/**
 * @brief Surcharge de l'operateur << pour afficher un sommet
 * @param ostream
 * @param sommet
 * @return
 */

Successeur Sommet::operator[](const size_t i) {
    return this -> adjacencyList.get(i);
}

Sommet &Sommet::operator=(const Sommet &sommet) {
    if (this != &sommet) {
        this->idVertex = sommet.idVertex;
            this->adjacencyList = sommet.adjacencyList;
    }
    return *this;
}


