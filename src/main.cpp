//---------------------------------------------------------------------
// Arquivo      : main.cpp
// Conteudo     : Algoritmos de Ordenacao
// Autor        : Aline Cristina Pinto (alinecristinapinto@ufmg.br)
//---------------------------------------------------------------------

#include <iostream>
#include <fstream>

#include "leitorLinhaComando.hpp"
#include "msgassert.hpp"

#include "listaPorPrioridade.hpp"
#include "verbete.hpp"

using namespace std;

int main(int argc, char* argv[]) {
    Implementacao implementacao = LeitorLinhaComando::buscarImplementacao(argc, argv);
    string arquivoEntrada = LeitorLinhaComando::buscarNomeArquivoEntrada(argc, argv);
    string arquivoSaida = LeitorLinhaComando::buscarNomeArquivoSaida(argc, argv);

    // cout << "implementacao: " << implementacao << endl;
    // cout << "arquivo entrada: " << arquivoEntrada << endl;
    // cout << "arquivo saida: " << arquivoSaida << endl;

    // ifstream arquivo(arquivoEntrada);
    // erroAssert(arquivo.is_open(), "Nao foi possivel ler o arquivo de entrada");

    Significado *significado = new Significado();
    significado->inserir("nome");

    Significado *significado1 = new Significado();
    significado1->inserir("nome1");

    Significado *significado2 = new Significado();
    significado2->inserir("nome2");

    Verbete verbete1 = Verbete("bruna", "a", significado);
    Verbete verbete2 = Verbete("aline", "a", significado1);
    Verbete verbete3 = Verbete("pedro", "a", significado);
    Verbete verbete4 = Verbete("amanda", "a", nullptr);
    Verbete verbete5 = Verbete("alice", "a", nullptr);
    Verbete verbete6 = Verbete("aline", "a", significado2);
    ListaPorPrioridade lista = ListaPorPrioridade();

    lista.inserir(verbete1);
    lista.inserir(verbete2);
    lista.inserir(verbete3);
    lista.inserir(verbete4);
    lista.inserir(verbete5);
    lista.inserir(verbete6);

    lista.imprimir();

    return 0;
}