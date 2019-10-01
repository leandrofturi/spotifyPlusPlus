#include "../bib/Midia.hpp"

Midia::Genero::Genero() {}

Midia::Genero::Genero(std::string nome, std::string sigla)
{
    this->nome = nome;
    this->sigla = sigla;
}

Midia::Genero::~Genero() {}

std::string Midia::Genero::getNome()
{
    return this->nome;
}

void Midia::Genero::setNome(std::string nome)
{
    this->nome = nome;
}

std::string Midia::Genero::getSigla()
{
    return this->sigla;
}

void Midia::Genero::setSigla(std::string sigla)
{
    this->sigla = sigla;
}

int qtdProdutos = 0;

Midia::Midia()
{
    this->qtdProdutos ++;
}

Midia::Midia(std::string nome, bool explicito, Genero* genero)
{
    this->nome = nome;
    this->explicito = explicito;
    this->genero = genero;

    this->qtdProdutos ++;
}

Midia::~Midia()
{
    this->qtdProdutos --;
}

std::string Midia::getNome()
{
    return this->nome;
}

void Midia::setNome(std::string nome)
{
    this->nome = nome;
}

bool Midia::getExplicito()
{
    return this->explicito;
}

void Midia::setExplicito(bool explicito)
{
    this->explicito = explicito;
}

int Midia::getQtdProdutos()
{
    return this->qtdProdutos;
}
