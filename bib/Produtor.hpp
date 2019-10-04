#ifndef _PRODUTOR_HPP_
#define _PRODUTOR_HPP_

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

    std::list<Midia*>* getMidias();
    void setMidias(std::list<Midia*>* midias);
    void addMidia(Midia* midia);
    void rmMidia(Midia* midia);
    void imprimeMidias();
};

#endif