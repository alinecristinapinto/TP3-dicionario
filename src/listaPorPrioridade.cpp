#include "listaPorPrioridade.hpp"

ListaPorPrioridade::ListaPorPrioridade(){
    this->primeiro = nullptr;
}

bool ListaPorPrioridade::vazia(){
    return this->primeiro == nullptr;
}

void ListaPorPrioridade::atribuirInsercao(No<Verbete> *aux, No<Verbete> *anterior, Verbete verbete){
    No<Verbete> *novo = new No<Verbete>{verbete, aux};
    erroAssert(novo != nullptr, "Erro ao alocar memoria para verbete");

    if(aux == this->primeiro){
        this->primeiro = novo;
    } else {
        anterior->proximo = novo;
    }
}

void ListaPorPrioridade::inserir(Verbete verbete){
    No<Verbete> *aux = this->primeiro, *anterior = nullptr; 

    while(true){
        if(aux == nullptr){
            this->atribuirInsercao(aux, anterior, verbete);

            return;
        } else if (verbete.palavra == aux->item.palavra && verbete.tipo == aux->item.tipo){
            if(verbete.significados) 
                aux->item.significados->inserir(verbete.significados->getPrimeiro()->item);

            return;
        } else if(verbete.palavra == aux->item.palavra && verbete.tipo < aux->item.tipo){
            this->atribuirInsercao(aux, anterior, verbete);

            return;
        } else if(verbete.palavra < aux->item.palavra){
            this->atribuirInsercao(aux, anterior, verbete);

            return;
        }

        anterior = aux;
        aux = aux->proximo;
    }
}

void ListaPorPrioridade::remover(string verbete, string tipoVerbete){
    if(this->vazia()) return;
    No<Verbete>* atual = this->primeiro;
    No<Verbete>* remover, *anterior = nullptr;

    while(atual){
        if(atual->item.palavra == verbete && atual->item.tipo == tipoVerbete) {
            if(anterior) {
                anterior->proximo = atual->proximo;
            } else {
                this->primeiro = atual->proximo;
            }
            remover = atual;
            break;
        }
        anterior = atual;
        atual = atual->proximo;
    }

    delete remover;
}

Verbete ListaPorPrioridade::pesquisar(string verbete, string tipoVerbete){
    No<Verbete>* atual = this->primeiro;

    while(atual){
        if(atual->item.palavra == verbete && atual->item.tipo == tipoVerbete) {
            return atual->item;
        }
        atual = atual->proximo;
    }

    return Verbete(nullptr, nullptr, nullptr);
}

void ListaPorPrioridade::imprimir(){
    if(this->vazia()) return;
    No<Verbete>* atual = this->primeiro;

    while(atual){
        cout << atual->item.palavra << " (" << atual->item.tipo << ")" << endl;
        if(atual->item.significados) atual->item.significados->imprimir();
        atual = atual->proximo;
    } 
}

No<Verbete>* ListaPorPrioridade::getLista(){
    return this->primeiro;
}

ListaPorPrioridade::~ListaPorPrioridade(){
    if(this->vazia()) return;
    No<Verbete>* atual = this->primeiro;

    while(atual){
        this->remover(atual->item.palavra, atual->item.tipo);
        atual = atual->proximo;
    }
}

