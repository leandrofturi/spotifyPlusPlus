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

void Usuario::escreveNoArquivo(std::ofstream& file)
{
    if(!file.is_open())
    {
        std::cout << "ERRO! Problemas ao abrir o Arquivo!" << std::endl;
        return;
    }

    file << this->getCodigo();
    file << ":";
    file << this->getNome();
    file << std::endl;
}