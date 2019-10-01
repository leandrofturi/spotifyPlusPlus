#ifndef _MIDIA_HPP_
#define _MIDIA_HPP_

#include <iostream>

class Midia
{
protected:
    std::string nome;

private:
    bool explicito;

public:
    int qtdProdutos;

    Midia();
    Midia(std::string nome, bool explicito);
    ~Midia();
};

#endif