#include "../bib/Assinante.hpp"

Assinante::Assinante() {}

Assinante::Assinante(std::string nome, int codigo)
    : Usuario(nome, codigo) {}

Assinante::~Assinante() {}