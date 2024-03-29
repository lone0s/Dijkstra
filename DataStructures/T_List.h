//
// Created by jeune on 23/12/2022
//
#pragma once
#include "T_Node.h"

template <typename T>
class T_List {
    private:
        T_Node<T>* start;

        //Iterateurs
        typedef T* iterator;
        typedef const T* const_iterator;

    public:
        //Constructeurs
        T_List() : start(nullptr) {};                                           // Sans argument
        explicit T_List(const T& elem) : start(new T_Node<T>(elem)) {};         // Avec un element
        explicit T_List(size_t size) : start(new T_Node<T>(size)) {};           // Avec une taille donnée
        T_List(const T_List<T>& list) { list.start                              // Par copie
        ? start = new T_Node<T>(*list.start)
        : start = nullptr; };

        //Destructeur
        ~T_List() {
            if (this -> start)
                delete start;
        }

        //Operations
        inline size_t length() const {return (start ? start->length() : 0);} ; // Retourne la taille de la liste
        inline bool isEmpty() const {return this -> start;};                   // Retourne si la liste est vide
        inline T get(size_t i) const;                                          // Retourne l'element à la position i
        inline T find(const T& elem) const;
        void add(const T& elem);                                               // Ajoute un element à la fin de la liste
        void add(const T_List<T>& list);                                       // Ajoute les elements d'une liste
        void remove(size_t i);                                                 // Supprime l'element à la position i

        //Operateurs
        T_List<T>& operator= (const T_List<T>& list);
        template<typename U>
        friend std::ostream& operator <<(std::ostream& ostream,const T_List<U>& list);

        //Iterateurs (pour for each loop)
        iterator begin() {                                  // Retourne un pointeur vers le premier element
            if(start)
                return this->start->begin() ;
            throw std::runtime_error("List is empty");
        }
        iterator end() {                                    // Retourne un pointeur vers le dernier element
            if(start)
                return this->start->end();
            throw std::runtime_error("List is empty");
        }
        const_iterator begin() const {                      // Retourne un pointeur constant vers le premier element
            if(start)
                return this->start->begin() ;
            throw std::runtime_error("List is empty");
        }
        const_iterator end() const {                        // Retourne un pointeur constant vers le dernier element
            if(start)
                return this->start->end();
            throw std::runtime_error("List is empty");
        }
};


/******************************************* SURCHARGE OPERATEUR *****************************************************/

/**
 * Surcharge de l'operateur << pour afficher une liste
 * @tparam T
 * @param ostream
 * @param list
 * @return
 */
template<typename T>
std::ostream& operator << (std::ostream& ostream, const T_List<T>& list) {
    std::cout << "[";
    for (size_t i = 0; i < list.length(); ++i) {
        std::cout << list.get(i);
        if (i != list.length() -1)
            std::cout << "; ";
    }
    std::cout << "]\n";
    return ostream;
}

/**
 * Surcharge de l'operateur = pour copier une liste
 * @tparam T
 * @param list
 * @return
 */
template<typename T>
T_List<T> &T_List<T>::operator=(const T_List<T> &list) {
    if (this != &list){
        if(start)
            delete start;
        if (list.start)
            this -> start = new T_Node<T>(*list.start);
        else
            this -> start = nullptr;
    }
    return *this;
}

/********************************************** PUBLIC FUNCTIONS *****************************************************/

/**
 * Retourne l'element à la position i
 * @tparam T type determiné à la compilation
 * @param i index
 * @return  ajout d'un element à la position i
 */
template<typename T>
void T_List<T>::add(const T &elem) {
    if (!this -> start)
        this -> start = new T_Node<T>(elem);
    else
        this -> start->add(elem);
}

/**
 * Ajoute les elements d'une liste à la fin de la liste
 * @tparam T type determiné à la compilation
 * @param list liste à ajouter
 */
template<typename T>
void T_List<T>::add(const T_List<T>& list) {
    if(!this -> start)
        this -> start = new T_Node<T>(*list.start);
    else
        this -> start->add(*list.start);
}

/**
 * Retire l'element à la position i
 * @tparam T type determiné à la compilation
 * @param i index
 */
template<typename T>
void T_List<T>::remove(size_t i) {
    if (this -> start)
        this -> start->remove(i);
}

/**
 * Retourne l'element à la position i
 * @tparam T type determiné à la compilation
 * @param i index
 * @return element à la position i
 */
template<typename T>
T T_List<T>::get(size_t i) const {
    return this -> start->get(i);
}

/**
 * Retourne l'element correspondant à celui recherché, lève une exception si l'élément n'est pas dans la liste
 * @tparam T
 * @param elem
 * @return
 */

template<typename T>
T T_List<T>::find(const T &elem) const {
    return this -> start->find(elem);
}

