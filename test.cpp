//
// Created by jeune on 22/12/2022.
//
#include <iostream>
#include "Successor/Successor.h"
#include "AdjacencyList/Node/Node.h"
#include "AdjacencyList/AdjacencyList.h";

using namespace AdjacencyList_Node;
using namespace Dijkstra_Successor;
using namespace Dijkstra_List;

int main() {

    Successor test(1,4);
    test.getSuccessorId() == 1 ? (std::cout << "Correct id\n") : (std::cout << "Wrong id\n");
    test.getSuccessorWeight() == 4 ? (std::cout << "Correct weight\n") : (std::cout << "Wrong weight\n");
    Successor array[] {Successor(1,1),Successor(2,2),Successor(3,3)};
    Successor arrayBis[] {Successor(-1,-1), Successor(-2,-2), Successor(-3,-3)};
    size_t sizeArray = sizeof(array) / sizeof(Successor);

    Node testNode(1,sizeArray,array);

    testNode.getNbSuccessors() == sizeArray ? std::cout << "Same size\n" : std::cout << "Different size\n";
    std::cout << "\nTest constructeur complet\n\n";
    for (size_t i = 0 ; i < testNode.getNbSuccessors() ; ++i) {
        testNode[i] == array[i] ? std::cout << "Same successor\n" : std::cout << "Different successors\n";
    }

    Node testAddSuccessors(2);
    testAddSuccessors.addSuccessors(sizeArray,array);
    std::cout << "\nTest constructeur trivial avec fonction d'ajout de successeurs\n\n";
    for (size_t i = 0 ; i < testNode.getNbSuccessors() ; ++i) {
        testAddSuccessors[i] == array[i] ? std::cout << "Same successor\n" : std::cout << "Different successors\n";
    }

    AdjacencyList list(-1,2,array);
    std::cout << list << std::endl;

    AdjacencyList listBis(1,3,arrayBis);
    std::cout << listBis << std::endl;

    list = listBis;
    std::cout << list << std::endl;

    return EXIT_SUCCESS;
}