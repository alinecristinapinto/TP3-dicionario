//---------------------------------------------------------------------
// Arquivo      : main.cpp
// Conteudo     : Algoritmos de Ordenacao
// Autor        : Aline Cristina Pinto (alinecristinapinto@ufmg.br)
//---------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <sstream>

#include "leitorLinhaComando.hpp"
#include "msgassert.hpp"
#include "verbete.hpp"
#include "dicionarioHash.hpp"
#include "dicionarioAvl.hpp"

using namespace std;

Verbete obterVerbete(stringstream *linha){
    Significado *significado =  new Significado();
    string verbete, tipo, significadoVerbete;

    *linha >> tipo >> verbete;
    significadoVerbete = linha->str().substr(linha->str().find("]")+1,  linha->str().size());

    if(significadoVerbete != "") significado->inserir(significadoVerbete);
    
    // substr para remover os colchetes
    return Verbete(verbete.substr(1, verbete.size() - 2), tipo, significado);
}

int main(int argc, char* argv[]) {
    Implementacao implementacao = LeitorLinhaComando::buscarImplementacao(argc, argv);
    string nomeArquivoEntrada = LeitorLinhaComando::buscarNomeArquivoEntrada(argc, argv);
    string nomeArquivoSaida = LeitorLinhaComando::buscarNomeArquivoSaida(argc, argv);

    ifstream arquivo(nomeArquivoEntrada);
    erroAssert(arquivo.is_open(), "Nao foi possivel ler o arquivo de entrada");

    ofstream arquivoSaida;
    arquivoSaida.open(nomeArquivoSaida);
    erroAssert(arquivoSaida.is_open(), "Nao foi possivel escrever no arquivo de saida");

    if(implementacao == HASH){
        DicionarioHash dicionario = DicionarioHash();
        
        for(string linha; getline(arquivo, linha);){
            stringstream streamLinha(linha);
            Verbete verbete = obterVerbete(&streamLinha);

            dicionario.inserir(verbete);
        }

        dicionario.escreverOrdenado(&arquivoSaida);

        dicionario.removerVerbetesComSignificado();

        dicionario.escreverOrdenado(&arquivoSaida);
     } else {
        DicionarioAvl dicionario = DicionarioAvl();

        for(string linha; getline(arquivo, linha);){
            stringstream streamLinha(linha);
            Verbete verbete = obterVerbete(&streamLinha);

            dicionario.inserir(verbete);
        }

        dicionario.escreverOrdenado(&arquivoSaida);

        dicionario.removerVerbetesComSignificado();

        dicionario.escreverOrdenado(&arquivoSaida);
    }

    arquivo.close();
    return 0;
}