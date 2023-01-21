#pragma once
#include <iostream>
#include <fstream>
#include <memory>
#include <sstream>

#include "Graph/Graph.h"

using namespace Dijkstra_DataTypes;
void jsp(Sommet& sommet, bool visited[], int couts[]){

}

inline void dijkstra(std::ifstream& infile, int s, std::ostream* outstream) {
    std::string line;
    std::getline(infile, line);

    int n = std::stoi(line);
    Graph graph(n);

    bool newNode = true;
    std::unique_ptr<Sommet> sommet;
    while (std::getline(infile, line)) {
        std::istringstream iss(line);
        if(newNode){
            int id, successeur, weight;
            iss >> id;
            iss >> successeur;
            sommet = std::make_unique<Sommet>(id);
            if(successeur == 0){
                graph.addSommet(*sommet);
            } else{
                iss >> weight;
                Successeur succ(successeur, weight);
                sommet->addSuccesseur(succ);
                newNode = false;
            }

        } else {
            int successeur, weight;
            iss >> successeur;
            if (successeur == 0) {
                graph.addSommet(*sommet);
                newNode = true;
            } else {
                iss >> weight;
                Successeur succ(successeur, weight);
                sommet->addSuccesseur(succ);
            }
        }
    }
    Sommet currentS = graph[s-1];

    std::cout << currentS.getId() << "(" << 0 << ", " << "_" << ")" << std::endl;

    bool visited[n];
    for(int i = 0; i < n; i++){
        visited[i] = false;
    }
    visited[s-1] = true;

    int couts[n];
    for(int i = 0; i < n; i++){
        couts[i] = 0;
    }

    Successeur smallestSucc = currentS[0];
    for(Successeur successeur : currentS.getAdjacencyList()){
        if(successeur.getSuccessorWeight() < smallestSucc.getSuccessorWeight()){
            smallestSucc = successeur;
        }
    }

    visited[smallestSucc.getSuccessorId()-1] = true;
    couts[smallestSucc.getSuccessorId()-1] += smallestSucc.getSuccessorWeight();

    std::cout << smallestSucc.getSuccessorId() << "(" << smallestSucc.getSuccessorWeight() << ", " << currentS.getId() << ")" << std::endl;

    for(Successeur successeur : graph[smallestSucc.getSuccessorId()-1].getAdjacencyList()){
        couts[successeur.getSuccessorId()-1] += successeur.getSuccessorWeight() + smallestSucc.getSuccessorWeight();
    }

    std::cout << graph << std::endl;



}


int main(){
    std::ifstream infile;
    infile.open("a");
    std::ostream* outstream;
    outstream = &std::cout;
    dijkstra(infile, 1, outstream);
    return 0;
}
