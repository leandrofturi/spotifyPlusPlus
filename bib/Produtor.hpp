#ifndef _PRODUTOR_HPP_
#define _PRODUTOR_HPP_

//ATRIBUTOS OK

#include <iostream>
#include <list>
#include "Usuario.hpp"
#include "Midia.hpp"

class Produtor : public Usuario
{
private:
    std::list<Midia*>* midias;

public:
    Produtor();
    Produtor(std::string nome, int codigo);
    ~Produtor();

    void addMidia(Midia* midia);
    void rmMidia(Midia* midia);
    Midia* buscaMidia(int codigo);
    void imprimeMidias();

    void imprimeNoArquivo(std::ofstream& file);
};

#endif