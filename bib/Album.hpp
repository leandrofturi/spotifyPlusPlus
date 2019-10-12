#ifndef _ALBUM_HPP_
#define _ALBUM_HPP_

// ATRIBUTOS OK

#include <iostream>
#include <list>
#include <algorithm>
#include "Musica.hpp"

class Album
{
private:
    std::string nome;
    int duracao;
    int anoLancamento;
    int qtdMusicas;

    std::list<Musica*>* musicas;

public:
    Album();
    Album(std::string nome, int duracao, int anoLancamento);
    ~Album();

    std::string getNome();
    void setNome(std::string nome);
    int getDuracao();
    void setDuracao(int duracao);
    int getAnoLancamento();
    void setAnoLancamento(int anoLancamento);
    int getQtdMusicas();

    std::list<Musica*>* getMusicas();
    void addMusica(Musica* musica);
    void rmMusica(Musica* musica);
    bool isMusica(Musica* musica);
};

#endif