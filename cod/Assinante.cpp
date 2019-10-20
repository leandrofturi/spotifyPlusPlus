#include "../bib/Assinante.hpp"

Assinante::Assinante()
{
    this->favoritas = new std::list<Midia*>;
}

Assinante::Assinante(std::string nome, int codigo)
    : Usuario(nome, codigo)
{
    this->favoritas = new std::list<Midia*>;
}

Assinante::~Assinante()
{
    delete this->favoritas;
}

void Assinante::addFavorita(Midia* favorita)
{
    this->favoritas->push_back(favorita);
}

void Assinante::rmFavorita(Midia* favorita)
{
    this->favoritas->remove(favorita);
}

bool Assinante::isFavorita(Midia* favorita)
{
    std::list<Midia*>::iterator it = find(this->favoritas->begin(), this->favoritas->end(), favorita);
    return it != this->favoritas->end();
}

void Assinante::imprimeFavoritas()
{
    std::cout << std::endl << "################################" << std::endl << std::endl;
    std::cout << "Midias favoritas de " << this->getNome() << ":" << std::endl;
    std::cout << std::endl << "################################" << std::endl << std::endl;

    for(Midia* aux : *this->favoritas)
    {
        std::cout << aux->getTipo() << std::endl;
        std::cout << "Nome: " << aux->getNome() << std::endl;
        std::cout << "Genero: " << aux->getGenero()->getNome() << std::endl;
        std::cout << "Duracao: " << aux->formataDuracao() << std::endl;
        std::cout << std::endl;
    }
    std::cout << "################################" << std::endl << std::endl;
}

void Assinante::imprimeNoArquivo(std::ofstream& file)
{
    
}