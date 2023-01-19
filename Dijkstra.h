//
// Created by jeune on 19/01/2023.
//

#pragma once
#include "Graph/Graph.h"

class Dijkstra {
    private:
        Djikstra_Data::Graph* graph;
        void loadFile(const std::string& filepath);
        inline bool fileHasBeenLoaded() {return (graph && !graph->isEmpty()); };
    public:
        void executeDijkstra(int sommetDepart, int sommetArrivee);
};

