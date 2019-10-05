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

void Usuario::setCodigo(int codigo)
{
    this->codigo = codigo;
}

void imprimeNoArquivo(std::ofstream& file)
{
    file.open("test.txt", std::ofstream::out | std::ofstream::app);
    file << "kkkkkk";
    file.close();
}