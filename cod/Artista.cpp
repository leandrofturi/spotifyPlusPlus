#include "../bib/Artista.hpp"

Artista::Artista()
{
    this->albuns = new std::list<Album*>;
}

Artista::Artista(std::string nome, int codigo)
    : Produtor(nome, codigo)
{
    this->albuns = new std::list<Album*>;
}

Artista::~Artista()
{
    delete this->albuns;
}

void Artista::addAlbum(Album* album)
{
    this->albuns->push_back(album);
}

void Artista::rmAlbum(Album* album)
{
    this->albuns->remove(album);
}

bool Artista::isAlbum(Album* album)
{
    std::list<Album*>::iterator it = find(this->albuns->begin(), this->albuns->end(), album);
    return it != this->albuns->end();
}

void Artista::imprimeNoArquivo(std::ofstream& file)
{

}