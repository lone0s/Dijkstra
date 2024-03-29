//
// Created by spaas on 22/01/2023.
//

#include "Dikestra.h"

Dikestra::Dikestra(std::ifstream& infile, std::ostream* outfile, size_t startVertex) {

    loadGraph(infile);
    runPrioq(startVertex);
    //runArray(startVertex);
    printResult(outfile, startVertex);

}

Dikestra::~Dikestra() {

    delete[] visited;
    delete[] couts;
    delete[] previous;

}


void Dikestra::loadGraph(std::ifstream &infile) {

    std::string line;
    std::getline(infile, line); // on recupere la première ligne

    graphSize = std::stoi(line); //la premiere ligne du fichier contient le nombre de sommets

    //on initialise les tableaux de couts, de précédents et de visite
    visited = new bool[graphSize];
    couts = new int[graphSize];
    previous = new int[graphSize];

    graph = Graph(graphSize); //on crée le graph

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


void Dikestra::runPrioq(size_t s) {

    s--; //on décrémente s car les sommets sont numérotés à partir de 1

    pQueue = T_PriorityQueue<Successeur>(); //initialisation de la file de priorité

    //initialisation des tableaux
    for (int i = 0; i < graphSize; i++) {
        visited[i] = false;                  //aucun sommet n'est visité
        couts[i] = INT_MAX;                  //les couts sont initialisés à l'infini
    }
    couts[s] = 0; //le cout du sommet de départ est 0
    visited[s] = true; //on marque le sommet de départ comme visité

    Sommet sommet = graph.getSommet(s); //on récupère le sommet de départ

    //ajout des successeurs du sommet de départ dans la file de priorité
    for (Successeur successeur : sommet.getAdjacencyList()){
        pQueue.add(successeur);
    }

    //cout du top de la file de priorité = cout du sommet de départ
    couts[pQueue.top().getId()-1] = pQueue.top().getWeight();
    previous[pQueue.top().getId()-1] = s; //le sommet de départ est le précédent du sommet de la file de priorité


    //on parcourt tous les sommets
    while (!pQueue.length()==0) { //tant que la file de priorité n'est pas vide

        Successeur successeur = pQueue.pop();
        int id = successeur.getId(); //on récupère l'id du sommet
        int cout = successeur.getWeight(); //on récupère le cout de l'arête

        visited[id-1] = true; //on marque le sommet comme visité

        Sommet sommet = graph.getSommet(id-1); //on récupère le sommet
        //on parcourt tous les successeurs du sommet
        for (size_t j = 0; j < sommet.getAdjacencyList().length(); j++){
            Successeur succ = graph[sommet.getId()-1].getAdjacencyList().get(j);
            int idSucc = succ.getId();
            int coutSucc = succ.getWeight();
            if (!visited[idSucc-1]) { //si le sommet n'est pas visité
                if (couts[idSucc-1] > cout + coutSucc) { //si le cout du sommet est supérieur au cout du sommet courant + le cout de l'arête
                    couts[idSucc-1] = cout + coutSucc; //on met à jour le cout du sommet
                    previous[idSucc-1] = id; //on met à jour le sommet précédent
                    succ.setWeight(cout + coutSucc); //on met à jour le cout de l'arête
                    if(pQueue.contains(succ)){ //si le sommet est déjà dans la file de priorité
                        pQueue.updatePriority(succ); //on met à jour la priorité du sommet
                    } else{
                        pQueue.add(succ); //sinon on ajoute le sommet à la file de priorité
                    }
                }
            }
        }

    }

}

void Dikestra::runArray(size_t s) {

    s--; //on décrémente s car les sommets sont numérotés à partir de 1

    //initialisation des tableaux
    for (int i = 0; i < graphSize; i++) {
        visited[i] = false; //aucun sommet n'est visité
        couts[i] = INT_MAX; //les couts sont initialisés à l'infini
    }
    couts[s] = 0; //le cout du sommet de départ est 0

    //on parcourt tous les sommets
    for (size_t i = 0; i < graphSize - 1; i++) {

        //on recupere le sommet de cout minimum non visité
        int sommetId = 0;
        int min = INT_MAX;
        for (int j = 0; j < graphSize; j++) {
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
            int successeurId = graph[sommetId].getAdjacencyList().get(j).getId()-1;
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
}

void Dikestra::printResult(std::ostream *outfile, size_t startVertex) {
    //on parcourt tous les sommets
    for(int i = 0; i < graphSize; i++){
        if(i == startVertex-1){ //si on est sur le sommet de départ
            (*outfile) << i+1 << "(0, _)" << std::endl;
        } else{
            int cout = couts[i];
            int previousId = previous[i];
            if (cout == INT_MAX) { //si le sommet n'est pas atteignable par le sommet de départ
                cout = -1;       //on met le cout à -1
                previousId = -2; //on met le sommet précédent à -2 car après on va incrémenter
            }
            (*outfile) << i+1 << "(" << cout << ", " << previousId+1 << ")" << std::endl;
        }

    }

}
