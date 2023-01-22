#include <iostream>
#include <fstream>
#include <memory>
#include <sstream>

#include "Graph/Graph.h"
#include "DataStructures/T_List.h"
using namespace Dijkstra_DataTypes;



inline void dijkstra(std::ifstream& infile, int s, std::ostream* outstream) {

    --s; //on décrémente s car dans notre implémentation les sommets sont numérotés de 0 à n et non de 1 à n

    std::string line;
    std::getline(infile, line);

    int n = std::stoi(line); //la premiere ligne du fichier contient le nombre de sommets

    Graph graph(n); //on crée un graphe de n sommets

    bool newNode = true; //indique si on est en train de lire un nouveau sommet

    Sommet sommet; //sommet courant
    while (std::getline(infile, line)) {

        std::istringstream iss(line); //on crée un flux de lecture à partir de la ligne courante

        if (newNode) { //si on est en train de lire un nouveau sommet

            int id, successeur, weight;  //id du sommet, id du successeur et cout de l'arête
            iss >> id;                   //on lit l'id du sommet
            iss >> successeur;           //on lit l'id du successeur
            sommet = Sommet(id);         //on crée le sommet

            if (successeur == 0) {       //si le successeur est 0 cela signifie que le sommet n'a pas de successeur
                graph.addSommet(sommet); //on ajoute le sommet au graphe
            } else {
                iss >> weight;          //sinon on lit le cout de l'arête
                Successeur succ(successeur, weight); //on crée le successeur
                sommet.addSuccesseur(succ);     //on ajoute le successeur au sommet
                newNode = false;                        //on indique que la prochaine ligne sera une ligne de successeur du sommet courant
            }

        } else {        //si on est en train de lire un sommet existant
            int successeur, weight;
            iss >> successeur;     //on lit l'id du successeur
            if (successeur == 0) { //si le successeur est 0 cela signifie que le sommet n'a plus de successeur
                graph.addSommet(sommet); //on ajoute le sommet au graphe
                newNode = true;          //on indique que le prochain sommet sera un nouveau sommet
            } else {
                iss >> weight;                           //sinon on lit le cout de l'arête
                Successeur succ(successeur, weight); //on crée le successeur
                sommet.addSuccesseur(succ);     //on ajoute le successeur au sommet courant
            }
        }
    }

    //on recupere le sommet de depart
    Sommet currentS = graph[s];

    //on affiche le sommet de depart
    (*outstream) << currentS.getId() << "(" << 0 << ", " << "_" << ")" << std::endl;

    //tableau des sommets visités
    bool visited[n];
    //tableau des couts
    int couts[n];
    //tableau des sommets précédents
    int previous[n];

    //initialisation des tableaux
    for (int i = 0; i < n; i++) {
        visited[i] = false; //aucun sommet n'est visité
        couts[i] = INT_MAX; //les couts sont initialisés à l'infini
    }
    couts[s] = 0; //le cout du sommet de départ est 0

    //on parcourt tous les sommets
    for (size_t i = 0; i < n - 1; i++) {
        //on recupere le sommet de cout minimum non visité
        int sommetId = 0;
        int min = INT_MAX;
        for (int j = 0; j < n; j++) {
            if (couts[j] < min && !visited[j]) {
                min = couts[j];
                sommetId = j;
            }
        }

        //on marque le sommet comme visité
        visited[sommetId] = true;

        //on parcourt tous les successeurs du sommet courant
        for (size_t j = 0; j < graph[sommetId].getAdjacencyList().length(); j++) {
            //on recupere le successeur et son cout
            int successeurId = graph[sommetId].getAdjacencyList().get(j).getId() - 1;
            int successeurWeight = graph[sommetId].getAdjacencyList().get(j).getWeight();

            //on met à jour les couts et les sommets précédents

            //si le sommet courant n'a pas un cout infini et que le nouveau cout est plus petit que l'ancien cout
            if (couts[sommetId] != INT_MAX && couts[successeurId] > couts[sommetId] + successeurWeight) {
                couts[successeurId] = couts[sommetId] + successeurWeight; //on met à jour le cout
                previous[successeurId] = sommetId;                        //on met à jour le sommet précédent

            //si le sommet courant a un cout infini et que le nouveau cout est plus petit que l'ancien cout
            } else if (couts[sommetId] == INT_MAX && couts[successeurId] > successeurWeight) {
                couts[successeurId] = successeurWeight; //on met à jour le cout
                previous[successeurId] = sommetId;     //on met à jour le sommet précédent
            }
        }
    }

    //on affiche pour chaque sommet son cout et son sommet précédent
    for (int i = 0; i < n; i++) {
        if (i != s) { //on ne prend pas en compte le sommet de départ
            int cout = couts[i];
            int previousId = previous[i];
            if (cout == INT_MAX) { //si le sommet n'est pas atteignable par le sommet de départ
                cout = -1;       //on met le cout à -1
                previousId = -1; //on met le sommet précédent à -1
            }
            (*outstream) << i+1 << "(" << cout << ", " << previousId+1 << ")" << std::endl;
        }
    }
}

