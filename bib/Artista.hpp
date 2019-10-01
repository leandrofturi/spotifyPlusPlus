#ifndef _ARTISTA_HPP_
#define _ARTISTA_HPP_

#include <iostream>
#include "Produtor.hpp"

class Artista : public Produtor
{
public:
    Artista();
    Artista(std::string nome, int codigo);
    ~Artista();
};

#endif