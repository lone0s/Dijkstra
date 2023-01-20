#pragma once
#include <iostream>
#include <fstream>

#include "Graph/Graph.h"

using namespace Dijkstra_DataTypes;
void dijkstra(std::ifstream& infile, int s,const std::ostream* outstream) {
    std::string line;
    std::getline(infile, line);

    int n = std::stoi(line);
    Graph graph((size_t)n);

    bool newNode = true;
    Sommet sommet;
    while (std::getline(infile, line)) {
        if (newNode) {
            int id = std::stoi(line);
            int successeur = std::stoi(line.substr(line.find(" ") + 1));
            int weight = std::stoi(line.substr(line.find(" ", line.find(" ") + 1) + 1));

            sommet = Sommet(id);
            Successeur succ(successeur, weight);
            sommet.addSuccesseur(succ);

            newNode = false;
        } else {
            if(std::stoi(line) == 0){
                graph.addSommet(sommet);
                newNode = true;
            }
                
                
            else {
                int successeur = std::stoi(line);
                int weight = std::stoi(line.substr(line.find(" ") + 1));
                Successeur succ(successeur, weight);
                sommet.addSuccesseur(succ);
            }
        }
    }
    std::cout << graph << std::endl;
    std::cout << "Sommet de depart : " << s << std::endl;
}

