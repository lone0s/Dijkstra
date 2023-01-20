//
// Created by ohno on 1/16/2023.
//
#pragma once
#include <ostream>

namespace Dijkstra_DataTypes {
    class Successeur {
    private:
        int idVertex;   // Identifie le sommet successeur
        int weight;     // Cout du chemin entre un sommet à définir et ce sommet successeur
    public:
        //Constructeurs
        Successeur(const int id, const int weight) : idVertex(id), weight(weight) {}; // Avec deux arguments
        Successeur() : idVertex(-1), weight(-1) {};                                   // Sans argument
        //Destructeur
        ~Successeur() = default;

        //Operations
        inline int getSuccessorId() const { return this->idVertex; };   // Retourne l'id du sommet successeur
        inline int getSuccessorWeight() const { return this->weight; }; // Retourne le cout [sommet x -> successeur]
        //Operateurs
        Successeur &operator=(const Successeur &successor);

        inline bool operator==(const Successeur &successor) const;

        friend std::ostream &operator<<(std::ostream &ostream, const Successeur &successor) {
            ostream << "[successeur : " << successor.getSuccessorId() <<
            " | cout : " << successor.getSuccessorWeight() << "]";
            return ostream;
        };

        bool operator>(const Successeur &successor) const;
    };
}