//
// Created by ohno on 1/16/2023.
//
#pragma once
#include <ostream>

namespace Dijkstra_DataTypes {
    class Successeur {
    private:
        int successeur;   // Identifie le successeur successeur
        int weight;     // Cout du chemin entre un successeur à définir et ce successeur successeur

    public:
        //Constructeurs
        Successeur(int id, const int weight) : successeur(id), weight(weight) {}; // Avec deux arguments
        Successeur() : successeur(-1), weight(-1) {};                                   // Sans argument
        //Destructeur
        ~Successeur() = default;

        //Operations
        inline int getSuccessorId() const { return this->successeur; };   // Retourne l'id du successeur successeur
        inline int getSuccessorWeight() const { return this->weight; }; // Retourne le cout [successeur x -> successeur]
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