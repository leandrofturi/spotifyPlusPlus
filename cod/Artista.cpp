#include "../bib/Artista.hpp"

Artista::Artista() {}

Artista::Artista(std::string nome, int codigo)
    : Produtor(nome, codigo) {}

Artista::~Artista() {}