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

/*std::ostream& operator<<(std::ostream &ostream, const Sommet &sommet) {

}*/

Successeur Sommet::operator[](const size_t i) {
    return this -> adjacencyList.get(i);
}


