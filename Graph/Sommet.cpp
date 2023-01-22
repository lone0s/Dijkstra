//
// Created by ohno on 23/12/2022.
//

#include "Sommet.h"
using namespace Dijkstra_DataTypes;

/******************************************* SURCHARGE OPERATEUR *****************************************************/

/**
 * @brief Surcharge de l'operateur << pour afficher un successeur
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

bool Sommet::operator==(const Sommet &sommet) const {
    return this -> idVertex == sommet.idVertex;
}


