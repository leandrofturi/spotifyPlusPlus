#include "../bib/Midia.hpp"

int qtdProdutos = 0;

Midia::Midia()
{
    this->qtdProdutos ++;
}

Midia::Midia(std::string nome, bool explicito)
{
    this->nome = nome;
    this->explicito = explicito;

    this->qtdProdutos ++;
}

Midia::~Midia()
{
    this->qtdProdutos --;
}