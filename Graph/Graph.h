//
// Created by ohno on 1/16/2023.
//

#pragma once
#include "Sommet.h"
#include "../DataStructures/T_List.h"


namespace Djikstra_Data{
    class Graph {
        T_List<Sommet> verticesList;
    public:
        Graph() : verticesList() {};
        //Rajouter constructeur avec taille donnée en paramètre
        //Penser a implémenter la possibilité de construire une liste de taille n
        ~Graph() = default;
        void add(const Sommet &sommet) { verticesList.add(sommet); };
        void addSommets(const T_List<Sommet>& sommets) { this->verticesList.add(sommets); };
        friend std::ostream &operator<<(std::ostream &ostream, const Graph &graph) {
            std::cout << "{\n";
            for (size_t i = 0; i < graph.verticesList.length(); ++i)
                std::cout << graph.verticesList.get(i);
            std::cout << "}\n";
            return ostream;
        }
};

}
