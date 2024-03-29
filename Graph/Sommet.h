//
// Created by ohno on 23/12/2022.
//

#pragma once
#include "../DataStructures/T_List.h"
#include "Successeur.h"

namespace Dijkstra_DataTypes{
    class Sommet {
        private:
            int idVertex;                    // Identifiant du sommet
            T_List<Successeur> adjacencyList;    // Liste des successeurs du sommet
            
        public:
            //Constructeurs
            explicit Sommet(const int id) : idVertex(id), adjacencyList() {};    // Avec un argument
            Sommet() : idVertex(-1), adjacencyList() {};                            // Sans argument
            
            //Destructeur
            ~Sommet() = default;
            
            //Operateurs
            friend std::ostream &operator<<(std::ostream &ostream, const Sommet &sommet) {
                std::cout << "Sommet: " << sommet.getId() << " - " << sommet.getAdjacencyList();
                return ostream;
            };
            Sommet &operator=(const Sommet &sommet);
            bool operator==(const Sommet &sommet) const;
            Successeur operator[](const size_t i);
            
            //Operations
            inline void addSuccesseur(const Successeur &successor) {                 // Ajoute un successeur à la liste
                this->adjacencyList.add(successor);
            }
            inline void addSuccesseurs(const T_List<Successeur> &listSuccesseurs) {  // Ajoute une liste de successeur
                this->adjacencyList.add(listSuccesseurs);
            }
            inline T_List<Successeur> getAdjacencyList() const { return this->adjacencyList; }
            inline int getId() const { return this->idVertex; }
    };
}
