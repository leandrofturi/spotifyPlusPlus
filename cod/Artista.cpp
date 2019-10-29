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
    if(this->buscaAlbum(album->getCodigo()) == NULL)
        this->albuns->push_back(album);
}

void Artista::rmAlbum(Album* album)
{
    this->albuns->remove(album);
}

Album* Artista::buscaAlbum(int codigo)
{
    for(Album* aux :*this->albuns)
        if(aux->getCodigo() == codigo) return aux;
    return NULL;
}

void Artista::imprimeMusicas()
{
    for(Album* aux : *this->albuns) aux->imprimeMusicas();
}