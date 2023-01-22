//
// Created by spaas on 22/01/2023.
//

#include "Dikestra.h"

Dikestra::Dikestra(std::ifstream& infile, std::ofstream* outfile, size_t startVertex) {

    loadGraph(infile);
    run(startVertex);

}

Dikestra::~Dikestra() {

    delete[] visited;
    delete[] couts;
    delete[] previous;

}


void Dikestra::loadGraph(std::ifstream &infile) {

    std::string line;
    std::getline(infile, line); // on recupere la première ligne

    int n = std::stoi(line); //la premiere ligne du fichier contient le nombre de sommets

    //on initialise les tableaux de couts, de précédents et de visite
    visited = new bool[n];
    couts = new int[n];
    previous = new int[n];

    graph = Graph(n); //on crée un graphe de n sommets

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
}


void Dikestra::run(size_t s, size_t n) {

    //initialisation des tableaux
    for (int i = 0; i < n; i++) {
        visited[i] = false; //aucun sommet n'est visité
        couts[i] = INT_MAX; //les couts sont initialisés à l'infini
    }
    couts[s] = 0; //le cout du sommet de départ est 0
}