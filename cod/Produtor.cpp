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

void Produtor::rmMidia(Midia* midia)
{
    this->midias->remove(midia);
}

void Produtor::imprimeMidias()
{
    std::cout << std::endl << "################################" << std::endl << std::endl;
    std::cout << "Produtos desenvolvidos por " << this->getNome() << ":" << std::endl;
    std::cout << std::endl << "################################" << std::endl << std::endl;
    std::cout << "Musicas" << std::endl;
    std::cout << std::endl << "################################" << std::endl << std::endl;

    std::list<Midia*>::iterator aux1;
    for(aux1 = this->midias->begin(); aux1 != this->midias->end(); aux1 ++)
    {
        // if (tipo == M)tipo
            std::cout << "Nome: " << (*aux1)->getNome() << std::endl;
            std::cout << "Genero: " << (*aux1)->getGenero()->getNome() << std::endl;
            std::cout << "Duracao: " << (*aux1)->getDuracao() << std::endl;
            std::cout << std::endl;
    }
    std::cout << "################################" << std::endl << std::endl;
    std::cout << "Podcasts" << std::endl;
    std::cout << std::endl << "################################" << std::endl << std::endl;
    for(aux1 = this->midias->begin(); aux1 != this->midias->end(); aux1 ++)
    {
        // if (tipo == P)tipo
            std::cout << "Nome: " << (*aux1)->getNome() << std::endl;
            std::cout << "Genero: " << (*aux1)->getGenero()->getNome() << std::endl;
            std::cout << "Duracao: " << (*aux1)->getDuracao() << std::endl;
            std::cout << std::endl;
    }
    std::cout << "################################" << std::endl << std::endl;
}