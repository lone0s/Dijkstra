//
// Created by ohno on 1/20/2023.
//

#include "Successeur.h"
using namespace Dijkstra_DataTypes;
Successeur &Successeur::operator=(const Successeur &successor) {
    if (this != &successor) {
        this->idVertex = successor.idVertex;
        this->weight = successor.weight;
    }
    return *this;
}
bool Successeur::operator==(const Successeur &successor) const {
    return (this->idVertex == successor.idVertex && this->weight == successor.weight);
}
/*std::ostream &operator<<(std::ostream &ostream, const Successeur& successor) {

}*/
bool Successeur::operator>(const Successeur &successor) const {
    return this->weight > successor.weight;
}