#include "../bib/Musica.hpp"

Musica::Musica() {}

Musica::Musica(std::string nome, int codigo, int duracao, int anoLancamento, Midia::Genero* genero)
    : Midia(nome, codigo, duracao, anoLancamento, 'M', genero) {}

Musica::~Musica() {}

Album* Musica::getAlbum()
{
    return this->album;
}

void Musica::setAlbum(Album* album)
{
    this->album = album;
}

void Musica::imprimeInfoProduto()
{
    std::cout << std::endl << "################################" << std::endl << std::endl;
    std::cout << "Musica" << std::endl;
    std::cout << std::endl << "################################" << std::endl << std::endl;
    std::cout << "Nome: " << this->getNome() << std::endl;
    std::cout << "Genero: " << this->getGenero()->getNome() << std::endl;
    std::cout << "Duracao: " << this->getDuracao() << std::endl;
    std::cout << std::endl << "################################" << std::endl << std::endl;
}