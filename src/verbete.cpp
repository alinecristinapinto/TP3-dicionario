#include "verbete.hpp"

Verbete::Verbete(){
    this->palavra = "";
}

Verbete::Verbete(string palavra, string tipo, Significado *significados){
    this->palavra = palavra;
    this->tipo = tipo;
    this->significados = significados;
}

Verbete::Verbete(const Verbete& verbete){
    this->palavra = verbete.palavra;
    this->tipo = verbete.tipo;
    this->significados = new Significado(); 

    No<string>* atual = verbete.significados->getPrimeiro();

    while(atual){
        this->significados->inserir(atual->item);
        atual = atual->proximo;
    }
}
