#ifndef DICIONARIOHASH_H
#define DICIONARIOHASH_H

#include <iostream>
#include "verbete.hpp"
#include "listaPorPrioridade.hpp"

#define M 26 // 26 letras do alfabeto

using namespace std;

/**
 * @brief Classe que representa um dicionario utilizando tabela hash
 */
class DicionarioHash {
public:
    /**
     * @brief Construtor generico da classe.
    */
    DicionarioHash();

    /**
     * @brief Insere um verbete na tabela hash
     * 
     * @param verbete Verbete
    */
    void inserir(Verbete verbete);

    /**
     * @brief Remove um verbete na tabela hash 
     * 
     * @param verbete Verbete
    */
    void remover(Verbete verbete);

    /**
     * @brief Pesquisar um verbete na tabela
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
     * @brief [DEBUG] imprime odernado
    */
    void imprimirOrdenado();

    /**
     * @brief Escreve ordenado TBD
    */
    void escreverOrdenado();

    /**
     * @brief Remove os verbetes do hash que possuem algum significado
    */
    void removerVerbetesComSignificado();

    /**
     * @brief Destrutor da classe
    */
    ~DicionarioHash();

private:
    ListaPorPrioridade tabela[M];
    string alfabeto = "abcdefghijklmnopqrstuvwxyz";

    /**
     * @brief Aplica formula do hash h(i) = i % 26 para encontrar indice da tabela referente ao verbete
     * 
     * @return int indice da tabela
    */
    int Hash(string verbete);
};

#endif