#include "leitorLinhaComando.hpp"

string LeitorLinhaComando::buscarArgumento(int argc, char* argv[], string param) {
    string argumento = "";

    for(int i=0; i<argc; i++){
        if(argv[i] == param && (i+1)< argc) {
            argumento = argv[i + 1];
            return argumento;
        }; 
    }

    return argumento;
}

bool LeitorLinhaComando::verificarParametroPresente(int argc, char* argv[], string param){
    for(int i=0; i<argc; i++){
        if(argv[i] == param) return true;
    }

    return false;
}

string LeitorLinhaComando::buscarNomeArquivoEntrada(int argc, char* argv[]) {
    string entrada = buscarArgumento(argc, argv, I_NOME_ARQUIVO_ENTRADA);
    erroAssert(entrada != "", "Nome do arquivo de entrada obrigatorio!");

    return entrada;
}

string LeitorLinhaComando::buscarNomeArquivoSaida(int argc, char* argv[]) {
    string saida = buscarArgumento(argc, argv, O_NOME_ARQUIVO_SAIDA);
    erroAssert(saida != "", "Nome do arquivo de saida obrigatorio!");

    return saida;
}

Implementacao LeitorLinhaComando::buscarImplementacao(int argc, char* argv[]){
    bool arvore = verificarParametroPresente(argc, argv, P_ARVORE);
    bool hash = verificarParametroPresente(argc, argv, P_HASH);
    erroAssert(arvore || hash, "A implementacao (arv ou hash) precisa ser informada!");
    erroAssert(!(arvore && hash), "Escolha apenas uma implementacao (arv ou hash)");

    return arvore ? ARVORE : HASH;
}
