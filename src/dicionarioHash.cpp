#include "dicionarioHash.hpp"

DicionarioHash::DicionarioHash(){
    for(int i=0; i<M; i++){
        this->tabela[i] = ListaPorPrioridade();
    }
}

int DicionarioHash::Hash(string verbete){
    char i = verbete[0];
    return tolower(i) % M;
}

void DicionarioHash::inserir(Verbete verbete){
    int indice = this->Hash(verbete.palavra);
    this->tabela[indice].inserir(verbete);
}

void DicionarioHash::remover(Verbete verbete){
    int indice = this->Hash(verbete.palavra);
    this->tabela[indice].remover(verbete.palavra, verbete.tipo);
}

Verbete DicionarioHash::pesquisar(string verbete, string tipoVerbete){
    int indice = this->Hash(verbete);
    return this->tabela[indice].pesquisar(verbete, tipoVerbete);
}

void DicionarioHash::imprimir(){
    for(int i=0; i<M; i++){
        if(!this->tabela[i].vazia()){
            this->tabela[i].imprimir();
        }
    }
}

