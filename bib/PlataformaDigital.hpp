#ifndef _PLATAFORMADIGITAL_HPP_
#define _PLATAFORMADIGITAL_HPP_

#include <iostream>
#include <list>
#include "Produtor.hpp"
#include "Midia.hpp"
#include "Assinante.hpp"

class PlataformaDigital
{
private:
    std::string nome;

    std::list<Assinante*>* assinantes;
    std::list<Produtor*>* produtores;
    std::list<Midia*>* midias;
    std::list<Midia::Genero*>* generos;

public:
    PlataformaDigital();
    PlataformaDigital(std::string nome);
    ~PlataformaDigital();

    std::string getNome();
    void setNome(std::string nome);

    std::list<Assinante*>* getAssinantes();
    void setAssinantes(std::list<Assinante*>* assinantes);
    void addAssinante(Assinante* assinante);
    std::list<Produtor*>* getProdutores();
    void setProdutores(std::list<Produtor*>* produtores);
    void addProdutor(Produtor* produtor);
    std::list<Midia*>* getMidias();
    void setMidias(std::list<Midia*>* midias);
    void addMidia(Midia* midia);
    std::list<Midia::Genero*>* getGeneros();
    void setGeneros(std::list<Midia::Genero*>* generos);
    void addGenero(Midia::Genero* genero);
};

#endif