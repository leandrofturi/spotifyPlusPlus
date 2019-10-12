#ifndef _PODCAST_HPP_
#define _PODCAST_HPP_

// ATRIBUTOS OK

#include <iostream>
#include "Midia.hpp"

class Podcast : public Midia
{
private:
    int qtdTemporadas;

public:
    Podcast();
    Podcast(std::string nome, int codigo, int duracao, int anoLancamento, Midia::Genero* genero, int qtdTemporadas);
    ~Podcast();

    int getQtdTemporadas();
    void setQtdTemporadas(int qtdTemporadas);

    void imprimeNoArquivo(std::ofstream& file);
    void imprimeInfoMidia();
};

#endif