#include "dicionarioHash.hpp"

DicionarioHash::DicionarioHash(){}

int DicionarioHash::Hash(string verbete){
    char i = verbete[0];
    bool maiusculo = i >= 65 && i <=90; // ASCII entre A e Z

    return !maiusculo ? tolower(i) % M : (tolower(i) % M) + 26;
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
    for(int i=0; i<N; i++){
        if(!this->tabela[i].vazia()){
            this->tabela[i].imprimir();
        }
    }
}

void DicionarioHash::imprimirOrdenado(){
    int indice = 0;

    for(int i=0; i<N; i++){
        string letra(1, this->alfabeto[i]);
        indice = this->Hash(letra);

        if(!this->tabela[indice].vazia()){
            this->tabela[indice].imprimir();
        }
    }
}

void DicionarioHash::removerVerbetesComSignificado(){
    No<Verbete>* aux = nullptr;

    for(int i=0; i<N; i++){
        if(!this->tabela[i].vazia()){
            aux = this->tabela[i].getLista();
            while (aux){
                if(aux->item.significados->getPrimeiro() != nullptr){
                    this->remover(aux->item);
                }
                aux = aux->proximo;
            }
            
        }
    }
}

void DicionarioHash::escreverOrdenado(ofstream *arquivoSaida){
    int indice = 0;

    for(int i=0; i<52; i++){
        string letra(1, this->alfabeto[i]);
        indice = this->Hash(letra);

        if(!this->tabela[indice].vazia()){
            this->tabela[indice].escrever(arquivoSaida);
        }
    }
}

DicionarioHash::~DicionarioHash(){
    No<Verbete>* aux = nullptr;

    for(int i=0; i<N; i++){
        if(!this->tabela[i].vazia()){
            aux = this->tabela[i].getLista();
            while (aux){
                this->remover(aux->item);
                aux = aux->proximo;
            }
        }
    }
}

