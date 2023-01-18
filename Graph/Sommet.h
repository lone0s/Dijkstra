//
// Created by ohno on 1/16/2023.
//

#pragma once
#include "../DataStructures/T_List.h"
#include "Successeur.h"

namespace Djikstra_Data{
    class Sommet {
        private:
            size_t idVertex;
            T_List<Successor> adjacencyList;
        public:
            explicit Sommet(const size_t id) : idVertex(id), adjacencyList() {};
            Sommet() : idVertex(-1), adjacencyList() {};
            ~Sommet() = default;
            friend std::ostream &operator<<(std::ostream &ostream, const Sommet &sommet) {
                std::cout << "Sommet: " << sommet.idVertex << " - " << sommet.adjacencyList;
                return ostream;
            }
            inline void addSuccesseur(const Successor &successor) {
                this->adjacencyList.add(successor);
            }
            inline void addSuccesseurs(const T_List<Successor> &listSuccesseurs) {
                this->adjacencyList.add(listSuccesseurs);
            }
            inline T_List<Successor> getAdjacencyList() const { return this->adjacencyList; }
    };

}