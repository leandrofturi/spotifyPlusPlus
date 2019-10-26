#ifndef _MUSICA_HPP_
#define _MUSICA_HPP_

#include <iostream>
#include <fstream>
#include <list>
#include "Midia.hpp"

class Musica : public Midia
{
private:
    std::string album;

public:
    Musica();
    Musica(std::string nome, int codigo, int duracao, int anoLancamento, Midia::Genero* genero);
    ~Musica();

    std::string getAlbum();
    void setAlbum(std::string album);

    void imprimeInfoMidia();
    void escreveNoArquivo(std::ofstream& file);
};

#endif