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

void Produtor::addMidia(Midia* midia)
{
    if(this->buscaMidia(midia->getCodigo()) == NULL)
        this->midias->push_back(midia);
}

void Produtor::rmMidia(Midia* midia)
{
    this->midias->remove(midia);
}

Midia* Produtor::buscaMidia(int codigo)
{
    for(Midia* aux :*this->midias)
        if(aux->getCodigo() == codigo) return aux;
    return NULL;
}

void Produtor::imprimeMidias()
{
    std::cout << std::endl << "################################" << std::endl << std::endl;
    std::cout << "Produtos desenvolvidos por " << this->getNome() << ":" << std::endl;
    std::cout << std::endl << "################################" << std::endl << std::endl;
    
    for(Midia* aux : *this->midias)
    {
        std::cout << aux->getTipo() << std::endl;
        std::cout << "Nome: " << aux->getNome() << std::endl;
        std::cout << "Genero: " << aux->getGenero()->getNome() << std::endl;
        std::cout << "Duracao: " << aux->getDuracao() << std::endl;
        std::cout << std::endl;
    }
    std::cout << "################################" << std::endl << std::endl;
}