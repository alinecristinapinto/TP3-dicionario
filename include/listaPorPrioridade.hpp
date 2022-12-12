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
     * @brief Retorna se lista esta vazia
     * 
     * @return bool true se lista vazia, false caso contrario
    */
    bool vazia();

    /**
     * @brief Insere um verbete a lista
     * 
     * @param verbete Verbete
    */
    void inserir(Verbete verbete);

    /**
     * @brief Remove um verbete a lista
     * 
     * @param palavra verbete
     * @param tipoVerbete tipo do verbete (a, n, v)
    */
    void remover(string verbete, string tipoVerbete);

    /**
     * @brief Pesquisar um verbete a lista
     * 
     * @param palavra verbete
     * @param tipoVerbete tipo do verbete (a, n, v)
    */
    Verbete pesquisar(string verbete, string tipoVerbete);

    /**
     * @brief [DEBUG] imprime verbetes
    */
    void imprimir();

    /**
     * @brief Destrutor da classe
    */
    ~ListaPorPrioridade();
protected:
    No<Verbete>* primeiro;
private:
    /**
     * @brief Funcao auxiliar que realiza a atruibuicao dos verbetes aos ponteiros da forma correta
    */
    void atribuirInsercao(No<Verbete> *atual, No<Verbete> *anterior, Verbete verbete);
};

#endif