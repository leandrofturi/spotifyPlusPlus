#include "../bib/Podcast.hpp"

Podcast::Podcast() {}

Podcast::Podcast(std::string nome, int codigo, int duracao, int anoLancamento, Midia::Genero* genero, int qtdTemporadas)
    : Midia(nome, codigo, duracao, anoLancamento, 'P', genero)
{
    this->qtdTemporadas = qtdTemporadas;
}

Podcast::~Podcast() {}

int Podcast::getQtdTemporadas()
{
    return this->qtdTemporadas;
}

void Podcast::setQtdTemporadas(int qtdTemporadas)
{
    this->qtdTemporadas = qtdTemporadas;
}

Podcaster* Podcast::getPodcaster()
{
    return this->podcaster;
}

void Podcast::setPodcaster(Podcaster* podcaster)
{
    this->podcaster = podcaster;
}

void Podcast::imprimeInfoProduto()
{
    std::cout << std::endl << "################################" << std::endl << std::endl;
    std::cout << "Podcast" << std::endl;
    std::cout << std::endl << "################################" << std::endl << std::endl;
    std::cout << "Nome: " << this->getNome() << std::endl;
    std::cout << "Genero: " << this->getGenero()->getNome() << std::endl;
    std::cout << "Duracao: " << this->getDuracao() << std::endl;
    std::cout << "Quantidade de temporadas: " << this->getQtdTemporadas() << std::endl;
    std::cout << std::endl << "################################" << std::endl << std::endl;
}