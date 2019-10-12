#include "../bib/Usuario.hpp"

Usuario::Usuario() {}

Usuario::Usuario(std::string nome, int codigo)
{
    this->nome = nome;
    this->codigo = codigo;
}

Usuario::~Usuario() {}

std::string Usuario::getNome()
{
    return this->nome;
}

void Usuario::setNome(std::string nome)
{
    this->nome = nome;
}

int Usuario::getCodigo()
{
    return this->codigo;
}