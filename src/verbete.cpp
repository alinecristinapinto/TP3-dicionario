#include "verbete.hpp"

Verbete::Verbete(){
    this->palavra = "";
}

Verbete::Verbete(string palavra, string tipo, Significado *significados){
    this->palavra = palavra;
    this->tipo = tipo;
    this->significados = significados;
}
