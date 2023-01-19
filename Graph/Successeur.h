//
// Created by ohno on 1/16/2023.
//
#pragma once
#include <ostream>

namespace Djikstra_Data {
    // Permet d'avoir un objet contenant le couple (sommet_successeur,cout)
    class Successeur {
        private:
            int idVertex;   // Identifie le sommet successeur
            int weight;     // Cout du chemin entre le sommet courant et le sommet successeur
        public:
            //Constructeurs
            Successeur(const int idSuccessor, const int weight) : idVertex(idSuccessor), weight(weight) {}; // Avec deux arguments
            Successeur() : idVertex(-1), weight(-1) {};                                                     // Sans argument
            //Destructeur
            ~Successeur() = default;
            //Operations
            inline int getSuccessorId() const { return this->idVertex; };   // Retourne l'identifiant du sommet successeur
            inline int getSuccessorWeight() const { return this->weight; }; // Retourne le cout du chemin sommet courant et sommet successeur
            //Operateurs
            inline Successeur& operator=(const Successeur &successor);
            inline bool operator==(const Successeur &successor) const;
            friend std::ostream &operator<<(std::ostream &ostream, const Successeur& successor);
            bool operator>(const Successeur &successor) const;
    };
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
    std::ostream &operator<<(std::ostream &ostream, const Successeur& successor) {
        ostream << "[successeur : " << successor.getSuccessorId() << " | cout : " << successor.weight << "]";
        return ostream;
    }
    bool Successeur::operator>(const Successeur &successor) const {
        return this->weight > successor.weight;
    }
}