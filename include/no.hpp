#ifndef NO_H
#define NO_H

/**
 * @brief Struct que representa um no de uma lista/fila generica
 */
template <typename T> struct No {  
    T item; 
    No* proximo; 
}; 

/**
 * @brief Struct que representa um no de uma arvore generica generica
 */
template <typename T> struct Nodo {  
    T* item; 
    Nodo* esquerda;
    Nodo* direita; 
    int altura;
}; 

#endif
