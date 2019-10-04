#ifndef _ARTISTA_HPP_
#define _ARTISTA_HPP_

#include <iostream>
#include <list>
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

    std::list<Album*>* getAlbuns();
    void setAlbuns(std::list<Album*>* albuns);
    void addAlbum(Album* album);
    void rmAlbum(Album* album);
};

#endif