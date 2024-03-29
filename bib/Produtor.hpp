#ifndef _PRODUTOR_HPP_
#define _PRODUTOR_HPP_

#include <iostream>
#include <list>
#include "Usuario.hpp"
#include "Midia.hpp"
#include "../cpp-utils/util/StringUtils.h"

class Produtor : public Usuario
{
private:
    std::list<Midia*>* midias;

    //OBJETIVOS ESPECIFICOS PARA GERACAO DE RELATORIOS, IMPLEMENTADO EM PLATAFORMADIGITAL
    friend std::list<Midia*>* getMidias(Produtor* produtor);

public:
    Produtor();
    Produtor(std::string nome, int codigo);
    virtual ~Produtor();

    void addMidia(Midia* midia);
    void rmMidia(Midia* midia);
    Midia* buscaMidia(int codigo);
    void imprimeMidias();

    void escreveMidiasNoArquivo(std::ofstream& file);
};

//METODO DE ORDENACAO
template <typename T>
bool ordenaCrescPorNome(T *obj1, T *obj2);

#endif