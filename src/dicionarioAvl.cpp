#include "dicionarioAvl.hpp"

DicionarioAvl::DicionarioAvl(){
    this->raiz = nullptr;
}

int DicionarioAvl::getAltura(Nodo<Verbete>* nodo){
    return nodo ? this->raiz->altura : 0;
}

int DicionarioAvl::maximo(int a, int b){
    return (a > b)? a : b;
}

Nodo<Verbete>* DicionarioAvl::rotacionarEsquerda(Nodo<Verbete>* nodo){
    Nodo<Verbete>* x = nodo->direita;
    Nodo<Verbete>* t2 = x->esquerda;

    x->esquerda = nodo;
    nodo->direita = t2;

    nodo->altura = this->maximo(this->getAltura(nodo->esquerda), this->getAltura(nodo->direita)) + 1;
    x->altura = this->maximo(this->getAltura(x->esquerda), this->getAltura(x->direita)) + 1;

    return x;
}

Nodo<Verbete>* DicionarioAvl::rotacionarDireita(Nodo<Verbete>* nodo){
    Nodo<Verbete>* x = nodo->esquerda;
    Nodo<Verbete>* t2 = x->direita;

    x->direita = nodo;
    nodo->esquerda = t2;

    nodo->altura = this->maximo(this->getAltura(nodo->esquerda), this->getAltura(nodo->direita)) + 1;
    x->altura = this->maximo(this->getAltura(x->esquerda), this->getAltura(x->direita)) + 1;

    return x;
}

int DicionarioAvl::getBalanceamento(Nodo<Verbete>* nodo){
    return nodo ? this->getAltura(nodo->esquerda) - this->getAltura(nodo->direita) : 0;
}

Nodo<Verbete>* DicionarioAvl::inserirRecursivo(Nodo<Verbete>* nodo, Verbete verbete){
    if(nodo == nullptr){
        Nodo<Verbete>* nodo = new Nodo<Verbete>{verbete, nullptr, nullptr, 1};
        return nodo;
    }

    if((verbete.palavra < nodo->item.palavra) || (verbete.palavra == nodo->item.palavra && verbete.tipo < nodo->item.tipo)){
        nodo->esquerda = inserirRecursivo(nodo->esquerda, verbete);
    } else if((verbete.palavra > nodo->item.palavra) || (verbete.palavra == nodo->item.palavra && verbete.tipo > nodo->item.tipo)){
        nodo->direita = inserirRecursivo(nodo->direita, verbete);
    } else {
        if(verbete.significados) 
            nodo->item.significados->inserir(verbete.significados->getPrimeiro()->item);

        return nodo;
    }

    // atualiza altura do node anterior
    nodo->altura = 1 + this->maximo(this->getAltura(nodo->esquerda), this->getAltura(nodo->direita));

    int balanceamento = this->getBalanceamento(nodo);

    // Casos
    bool chaveMenorItemAEsquerda = (verbete.palavra < nodo->esquerda->item.palavra) || (verbete.palavra == nodo->esquerda->item.palavra && verbete.tipo < nodo->esquerda->item.tipo);
    if (balanceamento > 1 && chaveMenorItemAEsquerda)
        return this->rotacionarDireita(nodo);
 
    bool chaveMaiorItemADireita = (verbete.palavra > nodo->direita->item.palavra) || (verbete.palavra == nodo->direita->item.palavra && verbete.tipo > nodo->direita->item.tipo);
    if (balanceamento < -1 && chaveMaiorItemADireita)
        return this->rotacionarEsquerda(nodo);
 
    bool chaveMaiorItemAEsquerda = (verbete.palavra > nodo->esquerda->item.palavra) || (verbete.palavra == nodo->esquerda->item.palavra && verbete.tipo > nodo->esquerda->item.tipo);
    if (balanceamento > 1 && chaveMaiorItemAEsquerda){
        nodo->esquerda =  this->rotacionarEsquerda(nodo->esquerda);
        return this->rotacionarDireita(nodo);
    }
 
    bool chaveMenorItemADireita = (verbete.palavra < nodo->direita->item.palavra) || (verbete.palavra == nodo->direita->item.palavra && verbete.tipo < nodo->direita->item.tipo);
    if (balanceamento < -1 && chaveMenorItemADireita){
        nodo->direita = this->rotacionarDireita(nodo->direita);
        return this->rotacionarEsquerda(nodo);
    }

    return nodo;
}

void DicionarioAvl::inserir(Verbete verbete){
    inserirRecursivo(this->raiz, verbete);
}
