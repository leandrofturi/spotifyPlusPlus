#ifndef _MUSICA_HPP_
#define _MUSICA_HPP_

#include <iostream>
#include "Midia.hpp"

class Album;

class Musica : public Midia
{
private:
    Album* album;

public:
    Musica();
    Musica(std::string nome, int codigo, int duracao, int anoLancamento, Midia::Genero* genero);
    ~Musica();

    Album* getAlbum();
    void setAlbum(Album* album);

    void imprimeInfoProduto();
};

#endif