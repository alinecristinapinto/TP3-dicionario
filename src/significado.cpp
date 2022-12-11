#include "significado.hpp"

Significado::Significado(){
    this->primeiro = nullptr;
    this->ultimo = nullptr;
}

void Significado::inserir(string significado){
    No<string>* novo = new No<string>{significado, nullptr};

    if(this->primeiro == nullptr){
        this->primeiro = novo;
        this->ultimo = novo;
    } else {
        this->ultimo->proximo = novo;
        this->ultimo = novo;
    }
}

void Significado::remover(){
    No<string>* remover = this->primeiro;

    this->primeiro = this->primeiro->proximo;

    delete remover;
}

void Significado::imprimir(){
    int posicao = 1;
    No<string>* atual = this->primeiro;

    while(atual->proximo != nullptr){
        cout << posicao <<". " << atual->item << endl;
        atual = atual->proximo;
        posicao++;
    }
}

Significado::~Significado(){
    while(!(this->primeiro == nullptr)){
        this->remover();
    }
}
