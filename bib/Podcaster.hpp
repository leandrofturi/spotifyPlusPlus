#ifndef _PODCASTER_HPP_
#define _PODCASTER_HPP_

#include <iostream>
#include "Produtor.hpp"

class Podcaster : public Produtor
{
public:
    Podcaster();
    Podcaster(std::string nome, int codigo);
    ~Podcaster();
};

#endif