#ifndef _ASSINANTE_HPP_
#define _ASSINANTE_HPP_

//ATRIBUTOS OK

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
    bool isFavorita(Midia* favorita);
    void imprimeFavoritas();

    void imprimeNoArquivo(std::ofstream& file);
};

#endif