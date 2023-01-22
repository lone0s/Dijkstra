//
// Created by jeune on 19/01/2023.
//

#include <fstream>
#include "Dijkstra.h"
#include "DataStructures/T_PriorityQueue.h"
#include <iostream>
#include <sstream>

using namespace Dijkstra_DataTypes;
size_t Dijkstra::loadFile(const std::string &filepath) {
    std::ifstream infile(filepath);
    std::string line;
    std::getline(infile, line);

    int n = std::stoi(line);
    this->graph = Graph(n);

    bool newNode = true;
    Sommet temp;
    while (std::getline(infile, line)) {
        std::stringstream iss(line);
        if (newNode) {
            int id, successeur, weight;
            iss >> id;
            iss >> successeur;
            temp = Sommet(id);
            if (successeur == 0) {
                graph.addSommet(temp);
            } else {
                iss >> weight;
                Successeur succ(successeur, weight);
                temp.addSuccesseur(succ);
                newNode = false;
            }
        } else {
            int successeur, weight;
            iss >> successeur;
            if (successeur == 0) {
                graph.addSommet(temp);
                newNode = true;
            } else {
                iss >> weight;
                Successeur succ(successeur, weight);
                temp.addSuccesseur(succ);
            }
        }
    }
    return n;
}
/**
 * @brief Algorithme pour réaliser l'algorithme de Dijkstra
 * @param sommetDepart
 * @param sommetArrivee
 */



//Algo dijkstra
// Initialisation
// D'abord on met tous les sommets à l'infini sauf le sommet de départ



void Dijkstra::executeDijkstra(const int idxSource) {
    if (fileHasBeenLoaded()){
        Sommet sommetDepart = getSommet(idxSource);
        addSuccessorsOfSommet(idxSource);
        setVisited(idxSource);
        tracker.add(this->getSommet(idxSource));
        while(priorityQueue.length() != 0) {
            Successeur successeur = priorityQueue.pop();
            Sommet sommetSuccesseur = getSommet(successeur.getVertexId());
            if(!visited[sommetSuccesseur.getId() -1]) {
                distances[sommetSuccesseur.getId() - 1] = distances[sommetDepart.getId() - 1] + successeur.getWeight();
                addSuccessorsOfSommet(sommetSuccesseur.getId());
                setVisited(sommetSuccesseur.getId());
                tracker.add(sommetSuccesseur);
            }
            else {
                if (distances[sommetSuccesseur.getId() - 1] > distances[sommetDepart.getId() - 1] + successeur.getWeight()) {
                    distances[sommetSuccesseur.getId() - 1] = distances[sommetDepart.getId() - 1] + successeur.getWeight();
                    tracker.add(sommetSuccesseur);
                }
            }
            sommetDepart = sommetSuccesseur;
        }

    }
}

void Dijkstra::setVisited(size_t id) {
    if(id > 0 && id < graph.length())
        visited[id-1] = true;
}

Dijkstra::Dijkstra(const Graph &graph, int sommetDepart, const std::string &filepath) {
    this -> graph = graph;
    this -> tracker = T_List<Sommet>();
    loadFile(filepath);
    if (fileHasBeenLoaded()) {
        distances = new int[this -> graph.length()];
        visited = new bool[this -> graph.length()];
        init(sommetDepart, this -> graph.length());
    }
}

Dijkstra::Dijkstra(const Graph &graph, int sommetDepart) {
    this -> graph = graph;
    this -> tracker = T_List<Sommet>();
    if (fileHasBeenLoaded()) {
        distances = new int[this -> graph.length()];
        visited = new bool[this -> graph.length()];
        init(sommetDepart, this -> graph.length());
    }
}

void Dijkstra::init(int sommetDepart, size_t nbSommets) {
    for (size_t i = 0; i < nbSommets; i++) {
        visited[i] = false;
        if (i == sommetDepart - 1) {
            distances[i] = 0;
        } else {
            distances[i] = INT_MAX;
        }
    }
}

void Dijkstra::addSuccessorsOfSommet(size_t id) {
    for(auto& succ : getSommet(id).getAdjacencyList()) {
        if (priorityQueue.contains(succ)) {
            priorityQueue.updatePriority(succ);
        } else
            priorityQueue.add(succ);
    }
}

Dijkstra::Dijkstra(const std::string &filepath, int sommetDepart) {
    size_t nbSommets = loadFile(filepath);
    if (fileHasBeenLoaded()) {
        distances = new int[nbSommets];
        visited = new bool[nbSommets];
/*        this->graph = Graph(nbSommets);*/
        this -> tracker = T_List<Sommet>(nbSommets);
        init(sommetDepart, nbSommets);
    }
}
