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

std::list<Album*>* Artista::getAlbuns()
{
    return this->albuns;
}

void Artista::setAlbuns(std::list<Album*>* albuns)
{
    this->albuns = albuns;
}

void Artista::addAlbum(Album* album)
{
    this->albuns->push_back(album);
}