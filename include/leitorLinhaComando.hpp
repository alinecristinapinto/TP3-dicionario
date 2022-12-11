#ifndef LEITORLINHACOMANDO_H
#define LEITORLINHACOMANDO_H

#include <iostream>
#include "msgassert.hpp" 

using namespace std;

enum Implementacao {
    ARVORE,
    HASH
};

const string P_ARVORE = "arv";
const string P_HASH = "hash";
const string I_NOME_ARQUIVO_ENTRADA = "-i";
const string O_NOME_ARQUIVO_SAIDA = "-o";

/**
 * @brief Classe responsavel pela leitura dos dados por linha de comando
*/
class LeitorLinhaComando {
public:
    /**
     * @brief Retorna o nome do arquivo de entrada
     * 
     * @param argc Numero de parametros
     * @param argv String com comando digitado
     * @return string nome do arquivo
    */
    static string buscarNomeArquivoEntrada(int argc, char* argv[]);

    /**
     * @brief Retorna o nome do arquivo de saida
     * 
     * @param argc Numero de parametros
     * @param argv String com comando digitado
     * @return string nome do arquivo
    */
    static string buscarNomeArquivoSaida(int argc, char* argv[]);

    /**
     * @brief Retorna o tipo de implementacao selecionada (arvore balanceada ou hash)
     * 
     * @param argc Numero de parametros
     * @param argv String com comando digitado
     * @return Implementacao Numero da implementacao selecionada
    */
    static Implementacao buscarImplementacao(int argc, char* argv[]);
    
private:
    /**
     * @brief  Retorna argumento do terminal baseado na opcao passada
     * 
     * @param argc Numero de parametros
     * @param argv String com comando digitado
     * @param param Parametro desejado
     * @return string Argumento do terminal referente ao parametro
    */
    static string buscarArgumento(int argc, char* argv[], string param); 

    /**
     * @brief  Retorna argumento do terminal baseado na opcao passada
     * 
     * @param argc Numero de parametros
     * @param argv String com comando digitado
     * @param parametro Parametro desejado
     * @return bool verdadeiro/falso para presenca de parametro no comando
    */
    static bool verificarParametroPresente(int argc, char* argv[], string parametro); 
};

#endif