#ifndef _ASSINANTE_HPP_
#define _ASSINANTE_HPP_

#include <iostream>
#include <list>
#include <algorithm>
#include "Usuario.hpp"
#include "Midia.hpp"

class Assinante : public Usuario
{
private:
    std::list<Midia*>* favoritas;

public:
    Assinante();
    Assinante(std::string nome, int codigo);
    ~Assinante();

    void addFavorita(Midia* favorita);
    void rmFavorita(Midia* favorita);
    Midia* buscaFavorita(int codigo);
    void imprimeFavoritas();

    //void imprimeNoArquivo(std::ofstream& file);
};

#endif