#include "../bib/Musica.hpp"

Musica::Musica() {}

Musica::Musica(std::string nome, int codigo, int duracao, int anoLancamento, Midia::Genero* genero)
    : Midia(nome, codigo, duracao, anoLancamento, genero)
{
    this->album = "";
    this->tipo = "MUSICA";
}

Musica::~Musica() {}

std::string Musica::getAlbum()
{
    return this->album;
}

void Musica::setAlbum(std::string album)
{
    this->album = album;
}

void Musica::imprimeInfoMidia()
{
    std::cout << std::endl << "################################" << std::endl << std::endl;
    std::cout << "Musica" << std::endl;
    std::cout << std::endl << "################################" << std::endl << std::endl;
    std::cout << "Nome: " << this->getNome() << std::endl;
    std::cout << "Genero: " << this->getGenero()->getNome() << std::endl;
    std::cout << "Duracao: " << this->getDuracao() << std::endl;
    std::cout << std::endl << "################################" << std::endl << std::endl;
}

void Musica::escreveNoArquivo(std::ofstream& file)
{
    if(!file.is_open())
    {
        std::cout << "ERRO! Problemas ao abrir o Arquivo!" << std::endl;
        return;
    }

    file << this->getNome();
    file << " : ";
    file << this->getTipo();
    file << " : ";
    file << this->getProdutores();
    file << " : ";
    file << this->formataDuracao();
    file << " : ";
    file << this->genero->getNome();
    file << " : ";
    file << this->album;
    file << " : ";
    file << this->anoLancamento;
    file << std::endl;
}