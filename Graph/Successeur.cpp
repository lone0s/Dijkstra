//
// Created by ohno on 23/12/2022.
//

#include "Successeur.h"
using namespace Dijkstra_DataTypes;
Successeur &Successeur::operator=(const Successeur &successor) {
    if (this != &successor) {
        this->successeur = successor.successeur;
        this->weight = successor.weight;
    }
    return *this;
}
bool Successeur::operator==(const Successeur &successor) const {
    return (this->successeur == successor.getSuccessorId());
}

bool Successeur::operator|=(const Successeur &successor) const {
    return (this->successeur == successor.getSuccessorId() && this->weight == successor.getSuccessorWeight());
}


bool Successeur::operator>(const Successeur &successor) const {
    return this->weight > successor.weight;
}

