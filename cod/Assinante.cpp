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

PlataformaDigital* Assinante::getPlataformaDigital()
{
    return this->plataformaDigital;
}

void Assinante::setPlataformaDigital(PlataformaDigital* plataformaDigital)
{
    this->plataformaDigital = plataformaDigital;
}

std::list<Midia*>* Assinante::getFavoritas()
{
    return this->favoritas;
}

void Assinante::setFavoritas(std::list<Midia*>* favoritas)
{
    this->favoritas = favoritas;
}

void Assinante::addFavorita(Midia* favorita)
{
    this->favoritas->push_back(favorita);
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
    std::cout << "Musicas" << std::endl;
    std::cout << std::endl << "################################" << std::endl << std::endl;

    std::list<Midia*>::iterator aux1;
    for(aux1 = this->favoritas->begin(); aux1 != this->favoritas->end(); aux1 ++)
    {
        if ((*aux1)->getTipo() == "Musica")
        {
            std::cout << "Nome: " << (*aux1)->getNome() << std::endl;
            std::cout << "Genero: " << (*aux1)->getGenero()->getNome() << std::endl;
            std::cout << "Duracao: " << (*aux1)->getDuracao() << std::endl;
            std::cout << std::endl;
        }
    }
    std::cout << "################################" << std::endl << std::endl;
    std::cout << "Podcasts" << std::endl;
    std::cout << std::endl << "################################" << std::endl << std::endl;
    for(aux1 = this->favoritas->begin(); aux1 != this->favoritas->end(); aux1 ++)
    {
        if ((*aux1)->getTipo() == "Podcast")
        {
            std::cout << "Nome: " << (*aux1)->getNome() << std::endl;
            std::cout << "Genero: " << (*aux1)->getGenero()->getNome() << std::endl;
            std::cout << "Duracao: " << (*aux1)->getDuracao() << std::endl;
            std::cout << std::endl;
        }
    }
    std::cout << "################################" << std::endl << std::endl;
}