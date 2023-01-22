//
// Created by spaas on 22/01/2023.
//
#pragma once
#include "Graph/Graph.h"
#include "DataStructures/T_PriorityQueue.h"
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
    T_PriorityQueue<Successeur> pQueue;  // add this line
    
    void loadGraph(std::ifstream& infile);
    void runPrioq(size_t s);
    void runArray(size_t s);
    void printResult(std::ostream* outfile, size_t startVertex);

public:
    Dikestra(std::ifstream& infile, std::ostream* outfile, size_t startVertex);
    ~Dikestra();
};

