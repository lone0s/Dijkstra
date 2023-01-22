//
// Created by jeune on 19/01/2023.
//

#pragma once
#include "Graph/Graph.h"
#include "DataStructures/T_PriorityQueue.h"

class Dijkstra {
public:
        Dijkstra_DataTypes::Graph graph;
        T_PriorityQueue<Dijkstra_DataTypes::Successeur> priorityQueue;
        int *distances;
        bool *visited;
        T_List<Dijkstra_DataTypes::Sommet> tracker;

        size_t loadFile(const std::string& filepath);
        inline bool fileHasBeenLoaded() const {return (!graph.isEmpty()); };
        void init(int sommetDepart, size_t nbSommets);
public:
        void executeDijkstra(int idxSource);
        Dijkstra(const Dijkstra_DataTypes::Graph& graph, int sommetDepart, const std::string& filepath);
        Dijkstra(const Dijkstra_DataTypes::Graph& graph, int sommetDepart);
        Dijkstra(const std::string& filepath, int sommetDepart);

        void setVisited(size_t id);
        inline Dijkstra_DataTypes::Sommet getSommet(size_t id) const {return graph.getSommet(id - 1); };
        inline void addSuccessorsOfSommet(size_t id);
};

