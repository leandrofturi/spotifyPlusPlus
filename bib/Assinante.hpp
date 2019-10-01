#ifndef _ASSINANTE_HPP_
#define _ASSINANTE_HPP_

#include <iostream>
#include "Usuario.hpp"

class Assinante : private Usuario
{
public:
    Assinante();
    Assinante(std::string nome, int codigo);
    ~Assinante();
};

#endif