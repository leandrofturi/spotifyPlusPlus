#include "../bib/Assinante.hpp"

Assinante::Assinante()
{
    this->midias = new std::list<Midia*>;
}

Assinante::Assinante(std::string nome, int codigo)
    : Usuario(nome, codigo)
{
    this->midias = new std::list<Midia*>;
}

Assinante::~Assinante()
{
    delete this->midias;
}

PlataformaDigital* Assinante::getPlataformaDigital()
{
    return this->plataformaDigital;
}

void Assinante::setPlataformaDigital(PlataformaDigital* plataformaDigital)
{
    this->plataformaDigital = plataformaDigital;
}

std::list<Midia*>* Assinante::getMidias()
{
    return this->midias;
}

void Assinante::setMidias(std::list<Midia*> *midias)
{
    this->midias = midias;
}

void Assinante::addMidia(Midia* midia)
{
    this->midias->push_back(midia);
}