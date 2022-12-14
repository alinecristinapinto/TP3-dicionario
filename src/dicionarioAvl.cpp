#include "dicionarioAvl.hpp"

DicionarioAvl::DicionarioAvl(){
    this->raiz = nullptr;
}

int DicionarioAvl::getAltura(Nodo<Verbete>* nodo){
    return nodo ? nodo->altura : 0;
}

int DicionarioAvl::maximo(int a, int b){
    return (a > b) ? a : b;
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
        Nodo<Verbete>* novo = new Nodo<Verbete>{verbete, nullptr, nullptr, 1};

        return novo;
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
    bool chaveMenorItemAEsquerda = nodo->esquerda && ((verbete.palavra < nodo->esquerda->item.palavra) || (verbete.palavra == nodo->esquerda->item.palavra && verbete.tipo < nodo->esquerda->item.tipo));
    if (balanceamento > 1 && chaveMenorItemAEsquerda)
        return this->rotacionarDireita(nodo);
 
    bool chaveMaiorItemADireita = nodo->direita && ((verbete.palavra > nodo->direita->item.palavra) || (verbete.palavra == nodo->direita->item.palavra && verbete.tipo > nodo->direita->item.tipo));
    if (balanceamento < -1 && chaveMaiorItemADireita)
        return this->rotacionarEsquerda(nodo);

 
    bool chaveMaiorItemAEsquerda = nodo->esquerda && ((verbete.palavra > nodo->esquerda->item.palavra) || (verbete.palavra == nodo->esquerda->item.palavra && verbete.tipo > nodo->esquerda->item.tipo));
    if (balanceamento > 1 && chaveMaiorItemAEsquerda){
        nodo->esquerda =  this->rotacionarEsquerda(nodo->esquerda);
        return this->rotacionarDireita(nodo);
    }
 
    bool chaveMenorItemADireita = nodo->direita && ((verbete.palavra < nodo->direita->item.palavra) || (verbete.palavra == nodo->direita->item.palavra && verbete.tipo < nodo->direita->item.tipo));
    if (balanceamento < -1 && chaveMenorItemADireita){
        nodo->direita = this->rotacionarDireita(nodo->direita);
        return this->rotacionarEsquerda(nodo);
    }

    return nodo;
}

void DicionarioAvl::inserir(Verbete verbete){
    this->raiz = inserirRecursivo(this->raiz, verbete);
}

Nodo<Verbete>* DicionarioAvl::removerRecursivo(Nodo<Verbete>* nodo, Verbete verbete){
    if(nodo == nullptr) return nodo;
    bool verbeteAEsquerda = verbete.palavra < nodo->item.palavra || (verbete.palavra == nodo->item.palavra && verbete.tipo < nodo->item.tipo);
    bool verbeteADireita = verbete.palavra > nodo->item.palavra || (verbete.palavra == nodo->item.palavra && verbete.tipo > nodo->item.tipo);

    if(verbeteADireita){
        nodo->esquerda = removerRecursivo(nodo->esquerda, verbete);
    } else if(verbeteADireita){
        nodo->direita = removerRecursivo(nodo->direita, verbete);
    } else { // Verbete encontrado
        if(nodo->esquerda == nullptr || nodo->direita == nullptr){
            Nodo<Verbete> *aux = nodo->esquerda ? nodo->esquerda : nodo->direita;
  
            if (aux == nullptr) { 
                aux = nodo;
                nodo = nullptr;
            } else { 
                *nodo = *aux; 
            } 

            delete aux;
        } else { // Verbete tem filhos a esquerda e a direita
                       // node with two children: Get the inorder
            // successor (smallest in the right subtree)
            // struct Node* temp = minValueNode(root->right);
  
            // Copy the inorder successor's data to this node
            // root->key = temp->key;
  
            nodo->direita = removerRecursivo(nodo->direita, verbete);
        }
    }

    if(nodo == nullptr) return nodo;

    nodo->altura = 1 + this->maximo(this->getAltura(nodo->esquerda), this->getAltura(nodo->direita));
    int balanceamento = this->getBalanceamento(nodo);

    // casos

    return nodo;
}

void DicionarioAvl::remover(Verbete verbete){
    this->raiz = this->removerRecursivo(this->raiz, verbete);
}

void DicionarioAvl::imprimirInorder(Nodo<Verbete>* nodo){
    if(nodo == nullptr) return;

    imprimirInorder(nodo->esquerda);
    cout << nodo->item.palavra << " (" << nodo->item.tipo << ")" << endl;
    nodo->item.significados->imprimir();
    imprimirInorder(nodo->direita);
}

void DicionarioAvl::imprimirOrdenado(){
    this->imprimirInorder(this->raiz);
}
