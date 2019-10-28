#include "../bib/Podcast.hpp"

Podcast::Podcast() {}

Podcast::Podcast(std::string nome, int codigo, int duracao, int anoLancamento, Midia::Genero* genero, int qtdTemporadas)
    : Midia(nome, codigo, duracao, anoLancamento, genero)
{
    this->tipo = "PODCAST";
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

void Podcast::imprimeInfoMidia()
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

void Podcast::escreveNoArquivo(std::ofstream& file)
{
    if(!file.is_open())
    {
        std::cout << "ERRO! Problemas ao abrir o Arquivo!" << std::endl;
        return;
    }

    file << this->getNome();
    file << ":";
    file << this->getTipo();
    file << ":";
    file << this->getProdutores();
    file << ":";
    file << this->getDuracao();
    file << ":";
    file << this->genero->getNome();
    file << ":";
    file << this->qtdTemporadas;
    file << ":";
    file << this->anoLancamento;
    file << std::endl;
}