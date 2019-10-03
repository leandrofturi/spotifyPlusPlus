#include "../bib/Musica.hpp"

Musica::Musica() {}

Musica::Musica(std::string nome, bool explicito, Genero* genero, int duracao, int anoLancamento)
    : Midia(nome, explicito, genero)
{
    this->duracao = duracao;
    this->anoLancamento = anoLancamento;
}

Musica::~Musica() {}

int Musica::getDuracao()
{
    return this->duracao;
}

void Musica::setDuracao(int duracao)
{
    this->duracao = duracao;
}

int Musica::getAnoLancamento()
{
    return this->anoLancamento;
}

void Musica::setAnoLancamento(int anoLancamento)
{
    this->anoLancamento = anoLancamento;
}

Album* Musica::getAlbum()
{
    return this->album;
}

void Musica::setAlbum(Album* album)
{
    this->album = album;
}