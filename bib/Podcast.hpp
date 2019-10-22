#ifndef _PODCAST_HPP_
#define _PODCAST_HPP_

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

    void imprimeInfoMidia();
    //void imprimeNoArquivo(std::ofstream& file);
};

#endif