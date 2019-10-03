#ifndef _MIDIA_HPP_
#define _MIDIA_HPP_

#include <iostream>
#include <list>
#include "Produtor.hpp"

class Midia
{
public:
    class Genero
    {
    private:
        std::string nome;
        std::string sigla;

    public:
        Genero();
        Genero(std::string nome, std::string sigla);
        ~Genero();

        std::string getNome();
        void setNome(std::string nome);
        std::string getSigla();
        void setSigla(std::string sigla);
    };

protected:
    std::string nome;

private:
    bool explicito;

    std::list<Produtor*>* produtores;

public:
    Genero* genero;

    int qtdProdutos;

    Midia();
    Midia(std::string nome, bool explicito, Genero* genero);
    ~Midia();

    std::string getNome();
    void setNome(std::string nome);
    bool getExplicito();
    void setExplicito(bool explicito);
    int getQtdProdutos();

    std::list<Produtor*>* getProdutores();
    void setProdutores(std::list<Produtor*>* produtores);
    void addProdutor(Produtor* produtor);
};

#endif