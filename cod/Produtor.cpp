#include "../bib/Produtor.hpp"

Produtor::Produtor()
{
    this->midias = new std::list<Midia*>;
}

Produtor::Produtor(std::string nome, int codigo)
    :Usuario(nome, codigo)
{
    this->midias = new std::list<Midia*>;
}

Produtor::~Produtor()
{
    delete this->midias;
}

std::list<Midia*>* Produtor::getMidias()
{
    return this->midias;
}

void Produtor::setMidias(std::list<Midia*>* midias)
{
    this->midias = midias;
}

void Produtor::addMidia(Midia* midia)
{
    this->midias->push_back(midia);
}
