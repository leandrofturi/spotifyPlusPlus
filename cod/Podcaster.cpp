#include "../bib/Podcaster.hpp"

Podcaster::Podcaster() {}

Podcaster::Podcaster(std::string nome, int codigo)
    : Produtor(nome, codigo) {}

Podcaster::~Podcaster() {}