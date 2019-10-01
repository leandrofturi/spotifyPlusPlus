#include "../bib/Produtor.hpp"

Produtor::Produtor() {}

Produtor::Produtor(std::string nome, std::string biografia)
    :Usuario(nome)
{
    this->biografia = biografia;
}

Produtor::~Produtor() {}
