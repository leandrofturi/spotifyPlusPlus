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
    Podcast(std::string nome, bool explicito, Genero* genero, int qtdTemporadas);
    ~Podcast();

    int getQtdTemporadas();
    void setQtdTemporadas(int qtdTemporadas);
};

#endif