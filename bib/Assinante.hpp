#ifndef _ASSINANTE_HPP_
#define _ASSINANTE_HPP_

#include <iostream>
#include <list>
#include "Usuario.hpp"
#include "Midia.hpp"

class PlataformaDigital;

class Assinante : public Usuario
{
private:
    PlataformaDigital* plataformaDigital;

    std::list<Midia*>* favoritas;

public:
    Assinante();
    Assinante(std::string nome, int codigo);
    ~Assinante();

    PlataformaDigital* getPlataformaDigital();
    void setPlataformaDigital(PlataformaDigital* plataformaDigital);
    std::list<Midia*>* getFavoritas();
    void setFavoritas(std::list<Midia*>* favoritas);
    void addFavorita(Midia* favorita);
    void rmFavorita(Midia* favorita);
    void imprimeFavoritas();
};

#endif