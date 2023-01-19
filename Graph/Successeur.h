//
// Created by ohno on 1/16/2023.
//
#pragma once
#include <ostream>

namespace Djikstra_Data {
    // Permet d'avoir un objet contenant le couple (sommet_successeur,cout)
    class Successor {
        private:
            int idVertex;   // Identifie le sommet successeur
            int weight;     // Cout du chemin entre le sommet courant et le sommet successeur
        public:
            //Constructeurs
            Successor(const int idSuccessor, const int weight) : idVertex(idSuccessor), weight(weight) {}; // Avec deux arguments
            Successor() : idVertex(-1), weight(-1) {};                                                     // Sans argument
            //Destructeur
            ~Successor() = default;
            //Operations
            inline int getSuccessorId() const { return this->idVertex; };   // Retourne l'identifiant du sommet successeur
            inline int getSuccessorWeight() const { return this->weight; }; // Retourne le cout du chemin sommet courant et sommet successeur
            //Operateurs
            inline Successor& operator=(const Successor &successor);
            inline bool operator==(const Successor &successor) const;
            friend std::ostream &operator<<(std::ostream &ostream, const Successor& successor);
            bool operator>(const Successor &successor) const;
    };
    Successor &Successor::operator=(const Successor &successor) {
        if (this != &successor) {
            this->idVertex = successor.idVertex;
            this->weight = successor.weight;
        }
        return *this;
    }
    bool Successor::operator==(const Successor &successor) const {
        return (this->idVertex == successor.idVertex && this->weight == successor.weight);
    }
    std::ostream &operator<<(std::ostream &ostream, const Successor& successor) {
        ostream << "[successeur : " << successor.getSuccessorId() << " | cout : " << successor.weight << "]";
        return ostream;
    }
    bool Successor::operator>(const Successor &successor) const {
        return this->weight > successor.weight;
    }
}