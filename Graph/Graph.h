//
// Created by ohno on 23/12/2022.
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
        bool isEmpty() const { return this->verticesList.length() == 0; };          // Retourne si la liste est vide
        //Destructeur
        ~Graph() = default;

        //Operations
        inline void addSommet(const Sommet &sommet) { verticesList.add(sommet); };            // Ajoute un successeur à la liste
        inline void addSommets(const T_List<Sommet> &sommets) { verticesList.add(sommets); }; // Ajoute une liste de sommets
        inline bool isEmpty() { return verticesList.length() == 0; };                         // Retourne si la liste est vide
        inline size_t length() { return verticesList.length(); };                             // Retourne le nombre de sommets
        inline T_List<Sommet> getVerticesList() const { return this->verticesList; };         // Retourne la liste des sommets
        inline Sommet getSommet(size_t i) const { return this->verticesList.get(i); };        // Retourne le successeur à l'indice i
        inline Sommet findSommet(int idSommet) const { return this->verticesList.find(Sommet(idSommet)) ;};

        //Operateurs
        friend std::ostream &operator<<(std::ostream &ostream, const Graph &graph);
        Sommet operator [](size_t i);
        Graph &operator=(const Graph &graph);
    };
}
