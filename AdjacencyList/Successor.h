//
// Created by jeune on 22/12/2022.
//

#pragma once

namespace AdjacencyList {
    class Successor {
    private:
        // Identifie le sommet successeur
        const int idVertex;
        // Poids entre le sommet parent et le sommet en question
        const int weight;

    public:
        inline explicit Successor(const int id,const int weight) : idVertex(id), weight(weight) {};

        ~Successor() = default;

        inline const int getSuccessorId() {
            return this -> idVertex;
        };

        inline const int getSuccessorWeight() {
            return this -> weight;
        };
    };
}
