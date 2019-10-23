#include "../bib/global.hpp"

template <class T>

bool compareNomes(T obj1, T obj2)
{
    return cpp_util::stringCompare(obj1.getNome(), obj2.getNome());
}

std::string formataHoras(double segundos)
{
    std::string duracao;
    time_t seconds(segundos);
    tm t = *gmtime(&seconds);
    duracao.append(std::to_string(t.tm_hour));
    duracao.append(":");
    duracao.append(std::to_string(t.tm_min));
    duracao.append(":");
    duracao.append(std::to_string(t.tm_sec));
    return duracao;
}