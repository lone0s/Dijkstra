//
// Created by jeune on 17/01/2023.
//
#pragma once
#include "T_Node.h"
template <typename T>

class T_PriorityQueue {
    private:
        T_Node<T> *start; //Code modulaire tout ça tout ça..
        //Methode du tri par tas
        void rearrange(size_t indexMin, size_t indexMax);   //Methode qui permet de remettre en ordre le tas
        void heapSort(size_t index);                        //Methode qui permet de trier le tas
        //Iterateurs
        typedef T* iterator;
        typedef const T* const_iterator;
    public:
        //Constructeurs
        T_PriorityQueue() : start(nullptr) {};                                                      // Sans argument
        explicit T_PriorityQueue(const T &elem) : start(new T_Node<T>(elem)) {};                    // Avec un element
        T_PriorityQueue(const T_PriorityQueue<T> &pQueue) : start(new T_Node<T>(*pQueue.start)) {}; // Par copie

        //Destructeur
        ~T_PriorityQueue() {
            if (this->start)
                delete start;
        }

        //Operations
        void add(const T &elem);                                                // Ajoute un element à la fin de la liste
        T pop();                                                                // Retire le premier element de la liste et le retourne
        inline size_t length() const { return (start ? start->length() : 0); }; // Retourne la taille de la liste
        inline bool isEmpty() const { return this->start; };                    // Retourne si la file est vide
        inline T top(size_t i) const {                                          // Retourne l'element à la position i (sans suppr)
            return (start ? start -> get(0) : throw std::runtime_error("Queue is empty !\n"));
        };

        //Operateurs
        template<typename U>
        friend std::ostream &operator<<(std::ostream &ostream, const T_PriorityQueue<U> &list); //Affichage

        //Iterateurs
        inline iterator begin() {if(start)                  // Retourne un pointeur vers le premier element
                return this->start->begin() ;
            throw std::runtime_error("List is empty");}
        inline iterator end() {if(start)                    // Retourne un pointeur vers le dernier element
                return this->start->end();
        throw std::runtime_error("List is empty");}
        inline const_iterator begin() const {if(start)      // Retourne un pointeur constant vers le premier element
                return this->start->begin() ;
        throw std::runtime_error("List is empty");}
        inline const_iterator end() const {if(start)        // Retourne un pointeur constant vers le dernier element
                return this->start->end();
        throw std::runtime_error("List is empty");}
};

/*********************************************************************************************************************/
/******************************************* SURCHARGE OPERATEUR *****************************************************/
/*********************************************************************************************************************/

/**
 * @brief Surcharge de l'operateur << pour afficher la liste
 * @tparam T
 * @param ostream
 * @param pQueue
 * @return
 */
template<typename T>
std::ostream& operator << (std::ostream& ostream, const T_PriorityQueue<T>& pQueue) {
    std::cout << "[";
    for (size_t i = 0; i < pQueue.length(); ++i) {
        std::cout << pQueue.start->get(i);
        if (i != pQueue.length() - 1)
            std::cout << "; ";
    }
    std::cout << "]\n";
    return ostream;
}
/*********************************************************************************************************************/
/********************************************* PRIVATE FUNCTIONS *****************************************************/
/*********************************************************************************************************************/

/**
 * @brief Methode qui permet de remettre en ordre le tas
 * @tparam T
 * @param indexMin
 * @param indexMax
 */
template <typename T>
void T_PriorityQueue<T>::rearrange(size_t indexMin, size_t indexMax) {
    size_t left = indexMin*2 + 1;
    size_t right = indexMin*2 + 2;
    size_t largest = indexMin;
    if (left < indexMax && this -> start->getData()[left] > this -> start->getData()[largest])
        largest = left;
    if (right < indexMax && this -> start->getData()[right] > this -> start->getData()[largest])
        largest = right;
    if (largest != indexMin) {
        std::swap(this -> start->getData()[indexMin],this -> start->getData()[largest]);
        rearrange(indexMax, largest);
    }
}

/**
 * @brief Methode qui permet de trier le tas
 * @tparam T
 * @param index
 */
template<typename T>
void T_PriorityQueue<T>::heapSort(size_t index) {
    for (int i = index / 2 - 1; i >= 0; --i)
        rearrange(i, index);
    for (int i = index - 1; i >= 0; --i) {
        std::swap(this -> start->getData()[0],this -> start->getData()[i]);
        rearrange(0, i);
    }
}
/*********************************************************************************************************************/
/********************************************** PUBLIC FUNCTIONS *****************************************************/
/*********************************************************************************************************************/

/**
 * @brief Ajoute un element à la fin de la liste
 * @tparam T
 * @param elem
 */
template<typename T>
void T_PriorityQueue<T>::add(const T &elem) {
    if (start) {
        start->add(elem);
        heapSort(start->length());
    } else
        start = new T_Node<T>(elem);
}

/**
 * @brief Retire le premier element de la liste
 * @tparam T
 * @return
 */
template<typename T>
T T_PriorityQueue<T>::pop() {
    if (start){
        T elem = start->get(0);
        start->remove(0);
        return elem;
    }
    throw std::runtime_error("Queue is empty");
}