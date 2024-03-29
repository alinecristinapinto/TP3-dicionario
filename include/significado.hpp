#ifndef SIGNIFICADO_H
#define SIGNIFICADO_H

#include <iostream>
#include <fstream>

#include "no.hpp"

using namespace std;

/**
 * @brief Classe que representa uma fila de significados
 */
class Significado {
public:
    No<string>* primeiro;
    No<string>* ultimo;

    /**
     * @brief Construtor generico da classe.
    */
    Significado();

    /**
     * @brief Insere um signigicado a fila de significados.
     * 
     * @param significado string que contem uma senteca sobre o significado de um verbete
    */
    void inserir(string significado);

    /**
     * @brief Remove primeiro signigicado da fila de significados.
    */
    void remover();

     /**
     * @brief retorna primeiro elemento da lista.
    */
    No<string>* getPrimeiro();

    /**
     * @brief [DEBUG] imprime fila de significados
    */
    void imprimir();

    /**
     * @brief escrever fila de significados
    */
    void escrever(ofstream *arquivoSaida);

    /**
     * @brief Destrutor da classe
    */
    ~Significado();
};

#endif