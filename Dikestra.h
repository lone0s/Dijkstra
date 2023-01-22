//
// Created by spaas on 22/01/2023.
//
#pragma once
#include "Graph/Graph.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace Dijkstra_DataTypes;
class Dikestra {

    Graph graph;
    size_t graphSize;

    bool* visited;
    int* couts;
    int* previous;
    
    void loadGraph(std::ifstream& infile);

    void run(size_t s);
    void printResult(std::ostream* outfile, size_t startVertex);

public:
    Dikestra(std::ifstream& infile, std::ostream* outfile, size_t startVertex);
    ~Dikestra();
    
    inline Sommet getSommet(size_t id) const {return graph.getSommet(id - 1); };
    inline bool fileHasBeenLoaded() const {return (!graph.isEmpty()); };
};

