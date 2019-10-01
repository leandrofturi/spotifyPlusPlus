#ifndef _ALBUM_HPP_
#define _ALBUM_HPP_

#include <iostream>
#include <list>
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

    void addMusica(Musica* musica);
};

#endif