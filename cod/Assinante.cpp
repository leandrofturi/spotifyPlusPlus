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
    if(this->buscaFavorita(favorita->getCodigo()) == NULL)
        this->favoritas->push_back(favorita);
}

Midia* Assinante::buscaFavorita(int codigo)
{
    for(Midia* aux :*this->favoritas)
        if(aux->getCodigo() == codigo) return aux;
    return NULL;
}

void Assinante::rmFavorita(Midia* favorita)
{
    this->favoritas->remove(favorita);
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