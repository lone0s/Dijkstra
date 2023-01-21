#include <iostream>
#include <fstream>
#include <memory>
#include <sstream>

#include "Graph/Graph.h"
#include "DataStructures/T_List.h"
using namespace Dijkstra_DataTypes;


inline void dijkstra(std::ifstream& infile, int s, std::ostream* outstream) {

    --s;

    std::string line;
    std::getline(infile, line);

    int n = std::stoi(line);
    Graph graph(n);

    bool newNode = true;
    std::unique_ptr<Sommet> sommet;
    while (std::getline(infile, line)) {
        std::istringstream iss(line);
        if (newNode) {
            int id, successeur, weight;
            iss >> id;
            iss >> successeur;
            sommet = std::make_unique<Sommet>(id);
            if (successeur == 0) {
                graph.addSommet(*sommet);
            } else {
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
    //somet de départ
    Sommet currentS = graph[s];

    std::cout << currentS.getId() << "(" << 0 << ", " << "_" << ")" << std::endl;

    //tableau des sommets visités
    bool visited[n];
    //tableau des couts
    int couts[n];

    //tableau des sommets précédents
    int previous[n];

    for (int i = 0; i < n; i++) {
        visited[i] = false;
        couts[i] = INT_MAX;
    }
    couts[s] = 0;

    for (size_t i = 0; i < n - 1; i++) {
        //get the min couts sommet not visited
        int sommetId = 0;
        int min = INT_MAX;
        for (int j = 0; j < n; j++) {
            if (couts[j] < min && !visited[j]) {
                min = couts[j];
                sommetId = j;
            }
        }

        visited[sommetId] = true;

        for (size_t j = 0; j < graph[sommetId].getAdjacencyList().length(); j++) {
            //update couts
            int successeurId = graph[sommetId].getAdjacencyList().get(j).getSuccessorId()-1;
            int successeurWeight = graph[sommetId].getAdjacencyList().get(j).getSuccessorWeight();

            if (couts[sommetId] != INT_MAX && couts[successeurId] > couts[sommetId] + successeurWeight) {
                couts[successeurId] = couts[sommetId] + successeurWeight;
                previous[successeurId] = sommetId;
            } else if (couts[sommetId] == INT_MAX && couts[successeurId] > successeurWeight) {
                couts[successeurId] = successeurWeight;
                previous[successeurId] = sommetId;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (i != s) {
            int cout = couts[i];
            int previousId = previous[i];
            if (cout == INT_MAX) {
                cout = -1;
                previousId = -1;
            }
            std::cout << i+1 << "(" << cout << ", " << previousId+1 << ")" << std::endl;
        }
    }



}

int main(){
    std::ifstream infile;
    infile.open("full.txt");
    std::ostream* outstream;
    outstream = &std::cout;
    dijkstra(infile, 1, outstream);
    return 0;
}
