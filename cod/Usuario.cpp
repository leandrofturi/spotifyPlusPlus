#include "../bib/Usuario.hpp"

Usuario::Usuario() {}

Usuario::Usuario(std::string nome)
{
    this->nome = nome;
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