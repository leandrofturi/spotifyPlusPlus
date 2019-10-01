#include "../bib/Podcast.hpp"

Podcast::Podcast() {}

Podcast::Podcast(std::string nome, bool explicito, Genero* genero, int qtdTemporadas)
    : Midia(nome, explicito, genero)
{
    this->qtdTemporadas = qtdTemporadas;
}

Podcast::~Podcast() {}

int Podcast::getQtdTemporadas()
{
    return this->qtdTemporadas;
}

void Podcast::setQtdTemporadas(int qtdTemporadas)
{
    this->qtdTemporadas = qtdTemporadas;
}