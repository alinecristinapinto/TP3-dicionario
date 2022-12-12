#ifndef LISTAPRIORIDADE_H
#define LISTAPRIORIDADE_H

#include <iostream>
#include "verbete.hpp"
#include "no.hpp"
#include "msgassert.hpp"

using namespace std;

/**
 * @brief Classe que implementa uma lista como ums fila ordenada por prioridade lexigrafica
*/
class ListaPorPrioridade {
public:
    /**
     * @brief Construtor generico da classe.
    */
    ListaPorPrioridade();

    /**
     * @brief Insere um verbete a lista
     * 
     * @param verbete Verbete
    */
    void inserir(Verbete verbete);

    /**
     * @brief [DEBUG] imprime fila de significados
    */
    void imprimir();

    /**
     * @brief Destrutor da classe
    */
    ~ListaPorPrioridade() = default;
protected:
    No<Verbete>* primeiro;
private:
    /**
     * @brief Funcao auxiliar que realiza a atruibuicao dos verbetes aos ponteiros da forma correta
    */
    void atribuirInsercao(No<Verbete> *atual, No<Verbete> *anterior, Verbete verbete);
};

#endif