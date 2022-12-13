#include "dicionarioHash.hpp"

DicionarioHash::DicionarioHash(){}

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

void DicionarioHash::imprimirOrdenado(){
    int indice = 0;

    for(int i=0; i<M; i++){
        string letra(1, this->alfabeto[i]);
        indice = this->Hash(letra);

        if(!this->tabela[indice].vazia()){
            this->tabela[indice].imprimir();
        }
    }
}

void DicionarioHash::removerVerbetesComSignificado(){
    No<Verbete>* aux = nullptr;

    for(int i=0; i<M; i++){
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

DicionarioHash::~DicionarioHash(){
    No<Verbete>* aux = nullptr;

    for(int i=0; i<M; i++){
        if(!this->tabela[i].vazia()){
            aux = this->tabela[i].getLista();
            while (aux){
                this->remover(aux->item);
                aux = aux->proximo;
            }
        }
    }
}

