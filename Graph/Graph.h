//
// Created by ohno on 1/16/2023.
//
#pragma once
#include "Sommet.h"
#include "../DataStructures/T_List.h"

namespace Djikstra_Data {
    class Graph {
        T_List<Sommet> verticesList;    // Liste des sommets du graphe
    public:
        //Constructeurs
        Graph() : verticesList() {};                                                // Sans argument
        explicit Graph(size_t verticesSize) : verticesList(verticesSize) {};   // Avec une taille de liste donnée
        explicit Graph(const Graph &graph) : verticesList(graph.verticesList) {};   // Par copie
        //Destructeur
        ~Graph() = default;
        //Operations
        void addSommet(const Sommet &sommet) { verticesList.add(sommet); };                 // Ajoute un sommet à la liste
        void addSommets(const T_List<Sommet> &sommets) { this->verticesList.add(sommets); }; // Ajoute une liste de sommets
        inline bool isEmpty() { return verticesList.length() == 0; };                            // Retourne si la liste est vide
        //Operateurs
        friend std::ostream &operator<<(std::ostream &ostream, const Graph &graph);
        Sommet operator [](size_t i);
    };

/*********************************************************************************************************************/
/******************************************* SURCHARGE OPERATEUR *****************************************************/
/*********************************************************************************************************************/

    /**
     * @brief Surcharge de l'operateur << pour afficher un graphe
     * @param ostream
     * @param graph
     * @return
     */
    std::ostream &operator<<(std::ostream &ostream, const Graph &graph) {
        std::cout << "{\n";
        for (size_t i = 0; i < graph.verticesList.length(); ++i)
            std::cout << graph.verticesList.get(i);
        std::cout << "}\n";
        return ostream;
    }

    Sommet Graph::operator[](size_t i) {
        return this -> verticesList.get(i);
    }
}
