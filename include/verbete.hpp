#ifndef VERBETE_H
#define VERBETE_H

#include <iostream>

#include "significado.hpp"

using namespace std;

/**
 * @brief Classe que representa um verbete
 */
class Verbete {
public:
    string palavra;
    string tipo;
    Significado *significados; 

    /**
     * @brief Construtor generico da classe.
    */
    Verbete();

    /**
     * @brief Construtor que inicializa algumas variaveis da classe.
     * 
     * @param palavra verbete
    */
    Verbete(string palavra, string tipo, Significado *significados);

    Verbete(const Verbete& verbete);

    /**
     * @brief Destrutor da classe
    */
    ~Verbete() = default;
};

#endif