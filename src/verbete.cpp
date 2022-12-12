#include "verbete.hpp"

Verbete::Verbete(string palavra, string tipo, Significado *significados){
    this->palavra = palavra;
    this->tipo = tipo;
    this->significados = significados;
}
