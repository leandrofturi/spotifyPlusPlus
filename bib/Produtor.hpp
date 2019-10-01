#ifndef _PRODUTOR_HPP_
#define _PRODUTOR_HPP_

#include <iostream>
#include "Usuario.hpp"

class Produtor : private Usuario
{
protected:
    std::string biografia;

public:
    Produtor();
    Produtor(std::string nome, std::string biografia);
    ~Produtor();
};

#endif