#ifndef _PODCAST_HPP_
#define _PODCAST_HPP_

#include <iostream>
#include "Midia.hpp"

class Podcaster;

class Podcast : public Midia
{
private:
    int qtdTemporadas;

    Podcaster* podcaster;

public:
    Podcast();
    Podcast(std::string nome, bool explicito, Genero* genero, int qtdTemporadas);
    ~Podcast();

    int getQtdTemporadas();
    void setQtdTemporadas(int qtdTemporadas);

    Podcaster* getPodcaster();
    void setPodcaster(Podcaster* podcaster);
};

#endif