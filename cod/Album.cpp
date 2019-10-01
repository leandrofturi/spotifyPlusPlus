#include "../bib/Album.hpp"

Album::Album()
{
    this->musicas = new std::list<Musica*>;
    this->qtdMusicas = 0;
}

Album::Album(std::string nome, int duracao, int anoLancamento)
{
    this->nome = nome;
    this->duracao = duracao;
    this->anoLancamento = anoLancamento;
    this->qtdMusicas = 0;

    this->musicas = new std::list<Musica*>;
}

Album::~Album()
{
    std::list<Musica*>::iterator it;
    for(it = this->musicas->begin(); it != this->musicas->end(); it ++)
    {
        delete *it;
    }

    delete this->musicas;
    this->qtdMusicas = 0;
}

std::string Album::getNome()
{
    return this->nome;
}

void Album::setNome(std::string nome)
{
    this->nome = nome;
}

int Album::getDuracao()
{
    return this->duracao;
}

void Album::setDuracao(int duracao)
{
    this->duracao = duracao;
}

int Album::getAnoLancamento()
{
    return this->anoLancamento;
}

void Album::setAnoLancamento(int anoLancamento)
{
    this->anoLancamento = anoLancamento;
}

std::list<Musica*>* Album::getMusicas()
{
    return this->musicas;
}

void Album::setMusicas(std::list<Musica*>* musicas)
{
    this->musicas = musicas;
}

void Album::addMusica(Musica* musica)
{
    this->musicas->push_back(musica);
}