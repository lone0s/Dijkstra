//
// Created by jeune on 26/12/2022.
//

#include "Successor.h"

using namespace Dijkstra_Successor;

Successor::Successor(const int idSuccessor, const int weight) : idVertex(idSuccessor), weight(weight) {};

//Constructeur sans arguments
Successor::Successor() : idVertex(-1),weight(-1) {};


