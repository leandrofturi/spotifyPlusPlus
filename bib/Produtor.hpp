#ifndef _PRODUTOR_HPP_
#define _PRODUTOR_HPP_

#include <iostream>
#include "Usuario.hpp"

class Produtor : public Usuario
{
public:
    Produtor();
    Produtor(std::string nome, int codigo);
    ~Produtor();
};

#endif