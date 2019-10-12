#ifndef _MUSICA_HPP_
#define _MUSICA_HPP_

// ATRIBUTOS OK

#include <iostream>
#include "Midia.hpp"

class Musica : public Midia
{
public:
    Musica();
    Musica(std::string nome, int codigo, int duracao, int anoLancamento, Midia::Genero* genero);
    ~Musica();

    void imprimeInfoMidia();
    void imprimeNoArquivo(std::ofstream& file);
};

#endif