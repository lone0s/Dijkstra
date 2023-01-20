//
// Created by ohno on 1/16/2023.
//
#pragma once
#include "Sommet.h"
#include "../DataStructures/T_List.h"

namespace Dijkstra_DataTypes {
    class Graph {
        T_List<Sommet> verticesList;    // Liste des sommets du graphe
    public:
        //Constructeurs
        Graph() : verticesList() {};                                                // Sans argument
        explicit Graph(size_t verticesSize) : verticesList(verticesSize) {};        // Avec une taille de liste donnée
        Graph(const Graph &graph) : verticesList(graph.verticesList) {};            // Par copie

        //Destructeur
        ~Graph() = default;

        //Operations
        inline void addSommet(const Sommet &sommet) { verticesList.add(sommet); };            // Ajoute un sommet à la liste
        inline void addSommets(const T_List<Sommet> &sommets) { verticesList.add(sommets); }; // Ajoute une liste de sommets
        inline bool isEmpty() { return verticesList.length() == 0; };                         // Retourne si la liste est vide
        inline size_t length() { return verticesList.length(); };                             // Retourne le nombre de sommets
        inline T_List<Sommet> getVerticesList() const { return this->verticesList; };         // Retourne la liste des sommets

        //Operateurs
        friend std::ostream &operator<<(std::ostream &ostream, const Graph &graph){
            std::cout << "{\n";
            for (size_t i = 0; i < graph.getVerticesList().length(); ++i)
                std::cout << graph.getVerticesList().get(i);
            std::cout << "}\n";
            return ostream;
        };
        Sommet operator [](size_t i);
    };
}
