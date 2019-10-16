#include "../bib/Album.hpp"

Album::Album()
{
    this->musicas = new std::list<Musica*>;
    this->qtdMusicas = 0;
}

Album::Album(std::string nome, int codigo, int duracao, int anoLancamento)
{
    this->nome = nome;
    this->codigo = codigo;
    this->duracao = duracao;
    this->anoLancamento = anoLancamento;
    this->qtdMusicas = 0;

    this->musicas = new std::list<Musica*>;
}

Album::~Album()
{
    for(Musica* aux : *this->musicas) delete aux;
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

int Album::getCodigo()
{
    return this->codigo;
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

int Album::getQtdMusicas()
{
    return this->qtdMusicas;
}

std::list<Musica*>* Album::getMusicas()
{
    return this->musicas;
}

void Album::addMusica(Musica* musica)
{
    this->musicas->push_back(musica);
}

void Album::rmMusica(Musica* musica)
{
    this->musicas->remove(musica);
}

bool Album::isMusica(Musica* musica)
{
    std::list<Musica*>::iterator it = find(this->musicas->begin(), this->musicas->end(), musica);
    return it != this->musicas->end();
}