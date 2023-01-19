//
// Created by ohno on 1/16/2023.
//

#pragma once
#include "../DataStructures/T_List.h"
#include "Successeur.h"

namespace Djikstra_Data{
    class Sommet {
        private:
            size_t idVertex;                    // Identifiant du sommet
            T_List<Successeur> adjacencyList;    // Liste des successeurs du sommet
        public:
            //Constructeurs
            explicit Sommet(const size_t id) : idVertex(id), adjacencyList() {};    // Avec un argument
            Sommet() : idVertex(-1), adjacencyList() {};                            // Sans argument
            //Destructor
            ~Sommet() = default;
            friend std::ostream &operator<<(std::ostream &ostream, const Sommet &sommet);
            Successeur operator[](const size_t i);
            inline void addSuccesseur(const Successeur &successor) {                 // Ajoute un successeur à la liste
                this->adjacencyList.add(successor);
            }
            inline void addSuccesseurs(const T_List<Successeur> &listSuccesseurs) {  // Ajoute une liste de successeur
                this->adjacencyList.add(listSuccesseurs);
            }
            inline T_List<Successeur> getAdjacencyList() const { return this->adjacencyList; }
    };

/******************************************* SURCHARGE OPERATEUR *****************************************************/

/**
 * @brief Surcharge de l'operateur << pour afficher un sommet
 * @param ostream
 * @param sommet
 * @return
 */
    std::ostream &operator<<(std::ostream &ostream, const Sommet &sommet) {
        std::cout << "Sommet: " << sommet.idVertex << " - " << sommet.adjacencyList;
        return ostream;
    }


    Successeur Sommet::operator[](const size_t i) {
        return this -> adjacencyList.get(i);
    }

}