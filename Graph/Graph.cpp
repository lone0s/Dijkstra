//
// Created by ohno on 1/20/2023.
//

#include "Graph.h"
using namespace Dijkstra_DataTypes;

/******************************************* SURCHARGE OPERATEUR *****************************************************/

/**
 * @brief Surcharge de l'operateur << pour afficher un graphe
 * @param ostream le flux de sortie
 * @param graph le graphe à afficher
 * @return
 */
/*std::ostream &operator<<(std::ostream &ostream, const Graph &graph) {

}*/

Sommet Graph::operator[](size_t i) {
    return this -> verticesList.get(i);
}