#ifndef _USUARIO_HPP_
#define _USUARIO_HPP_

#include <iostream>

class Usuario
{
protected:
    std::string nome;

public:
    Usuario();
    Usuario(std::string nome);
    ~Usuario();

    std::string getNome();
    void setNome(std::string nome);
};

#endif