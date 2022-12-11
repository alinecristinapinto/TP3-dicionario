//---------------------------------------------------------------------
// Arquivo      : main.cpp
// Conteudo     : Algoritmos de Ordenacao
// Autor        : Aline Cristina Pinto (alinecristinapinto@ufmg.br)
//---------------------------------------------------------------------

#include <iostream>

#include "leitorLinhaComando.hpp"

using namespace std;

int main(int argc, char* argv[]) {
    Implementacao implementacao = LeitorLinhaComando::buscarImplementacao(argc, argv);
    string arquivoEntrada = LeitorLinhaComando::buscarNomeArquivoEntrada(argc, argv);
    string arquivoSaida = LeitorLinhaComando::buscarNomeArquivoSaida(argc, argv);

    cout << "implementacao: " << implementacao << endl;
    cout << "arquivo entrada: " << arquivoEntrada << endl;
    cout << "arquivo saida: " << arquivoSaida << endl;

    return 0;
}