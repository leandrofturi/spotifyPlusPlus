#include "../bib/global.hpp"

template <class T>

bool compareNomes(T obj1, T obj2)
{
    return cpp_util::stringCompare(obj1.getNome(), obj2.getNome());
}