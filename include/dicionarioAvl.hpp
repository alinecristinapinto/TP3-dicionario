#ifndef DICIONARIOAVL_H
#define DICIONARIOAVL_H

#include <iostream>
#include <fstream>
#include "no.hpp"
#include "verbete.hpp"

using namespace std;

/**
 * @brief Classe que representa um dicionario utilizando arvore balanceada (AVL)
 * https://www.geeksforgeeks.org/insertion-in-an-avl-tree/
*/
class DicionarioAvl {
public:
    /**
     * @brief Construtor generico da classe.
    */
    DicionarioAvl();

    /**
     * @brief Insere um verbete na arvore
     * 
     * @param verbete Verbete
    */
    void inserir(Verbete* verbete);

    /**
     * @brief Remove um verbete da arvore
     * 
     * @param verbete Verbete
    */
    void remover(Verbete* verbete);

    /**
     * @brief [DEBUG] imprime verbetes
    */
    void imprimir();

    /**
     * @brief [DEBUG] imprime odernado
    */
    void imprimirOrdenado();

    /**
     * @brief Escreve ordenado
    */
    void escreverOrdenado(ofstream *arquivoSaida);

    /**
     * @brief Remove os verbetes do hash que possuem algum significado
    */
    void removerVerbetesComSignificado();

    /**
     * @brief Destrutor da classe
    */
    ~DicionarioAvl() = default;

private:
    Nodo<Verbete>* raiz;

    /**
     * @brief Utilitario que retorna a altura de uma subarvore.
    */
    int getAltura(Nodo<Verbete>* nodo);

    /**
     * @brief Utilitario que retorna o maior valor entre dois inteiros
    */
    int maximo(int a , int b);

    /**
     * @brief Utilitario que realiza o rotacaionamento a esquerda
    */
    Nodo<Verbete>* rotacionarEsquerda(Nodo<Verbete>* nodo);

    /**
     * @brief Utilitario que realiza o rotacaionamento a direta
    */
    Nodo<Verbete>* rotacionarDireita(Nodo<Verbete>* nodo);

    /**
     * @brief Utilitario que retorna o fator de balanceamento de um nodo
    */
    int getBalanceamento(Nodo<Verbete>* nodo);

    /**
     * @brief Insere um verbete na arvore de forma recursiva
    */
    Nodo<Verbete>* inserirRecursivo(Nodo<Verbete>* nodo, Verbete* verbete);

    /**
     * @brief Remove um verbete na tabela hash
    */
    Nodo<Verbete>* removerRecursivo(Nodo<Verbete>* nodo, Verbete* verbete);
   
    /**
     * @brief Pesquisa e retorna o menor nodo de uma arvore (nao vazia)
    */
    Nodo<Verbete>* buscarMenorVerbete(Nodo<Verbete>* nodo);

    /**
     * @brief Retorna verbete com significado
    */
    Verbete* verbeteComSignificado(Nodo<Verbete>* nodo);

    /**
     * @brief [DEBUG] imprime inorder
    */
    void imprimirInorder(Nodo<Verbete>* nodo);

    /**
     * @brief escreve inorder
    */
    void escreverInorder(Nodo<Verbete>* nodo, ofstream *arquivoSaida);
};

#endif