#ifndef _ARTISTA_HPP_
#define _ARTISTA_HPP_

#include <iostream>
#include <list>
#include <algorithm>
#include "Produtor.hpp"
#include "Album.hpp"

class Artista : public Produtor
{
private:
    std::list<Album*>* albuns;

public:
    Artista();
    Artista(std::string nome, int codigo);
    ~Artista();

    void addAlbum(Album* album);
    void rmAlbum(Album* album);
    Album* buscaAlbum(int codigo);
    void imprimeMusicas();

    //void imprimeNoArquivo(std::ofstream& file);
};

#endif