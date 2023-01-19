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
            T_List<Successor> adjacencyList;    // Liste des successeurs du sommet
        public:
            //Constructeurs
            explicit Sommet(const size_t id) : idVertex(id), adjacencyList() {};    // Avec un argument
            Sommet() : idVertex(-1), adjacencyList() {};                            // Sans argument
            //Destructor
            ~Sommet() = default;
            friend std::ostream &operator<<(std::ostream &ostream, const Sommet &sommet);
            inline void addSuccesseur(const Successor &successor) {                 // Ajoute un successeur à la liste
                this->adjacencyList.add(successor);
            }
            inline void addSuccesseurs(const T_List<Successor> &listSuccesseurs) {  // Ajoute une liste de successeurs
                this->adjacencyList.add(listSuccesseurs);
            }
            inline T_List<Successor> getAdjacencyList() const { return this->adjacencyList; }   // Retourne la liste d'adjacence
    };

/*********************************************************************************************************************/
/******************************************* SURCHARGE OPERATEUR *****************************************************/
/*********************************************************************************************************************/

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

}